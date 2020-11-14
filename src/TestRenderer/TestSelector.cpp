#include "TestSelector.h"
#include <tchar.h>
#include <cctype>

TestSelector::TestSelector(CefRefPtr<CefDOMNode> node, const CefString& selectors, bool once):
	_rootNode(node){
	_curIndex = 0;
	if (!selectors.empty()) {
		SplitPath(selectors);
	}

	for (auto v: _namedLists){
		OutputDebugString(v.c_str());
	}
	OutputDebugString(L"======== path ==========");
}

TestSelector::~TestSelector() {
	_rootNode = nullptr;
	_resultNodes.clear();
	_pendingNodes.clear();
}

void TestSelector::SplitPath(const CefString& s) {
	size_t begin = 0;
	size_t pointer = 0;
	size_t length = s.length();
	const wchar_t* segment = s.c_str();

	_namedLists.clear();
	while (pointer < length){
		if (segment[pointer] == ' ') {
			if ((pointer - begin) > 0) {
				_namedLists.emplace_back(&segment[begin], pointer - begin);
			}
			begin = pointer + 1;
		}
		pointer++;
	}
	if (begin < length) {
		_namedLists.emplace_back(&segment[begin], length - begin);
	}
}

int TestSelector::SplitString(const std::wstring& s, const std::wstring& p, std::vector<std::wstring>& ret) {
	size_t begin = 0;
	size_t pointer = 0;
	size_t length = s.length();
	const wchar_t* segment = s.c_str();

	ret.clear();
	while (pointer < length)
	{
		pointer = s.find(p,begin);
		if (pointer == std::wstring::npos) {
			break;
		}
		ret.emplace_back(&s[begin], pointer - begin);
		begin = pointer + p.length();
	}
	if (begin < length) {
		ret.emplace_back(&s[begin], s.length() - begin);
	}
	return ret.size();
}

bool TestSelector::Find(void) {
	if (_namedLists.empty()) {
		return false;
	}
	_pendingNodes.push_back(_rootNode);

	int index = 0;
	while (index < _namedLists.size())
	{
		_curIndex = index;
		Iterator(index);

		index++;
	}
	return !_pendingNodes.empty();
}

CefRefPtr<CefDOMNode> TestSelector::GetFirstElement() {
	if (!_pendingNodes.empty()) {
		return _pendingNodes.front();
	}
	return nullptr;
}

void TestSelector::GetAllElement(std::vector<CefRefPtr<CefDOMNode>>& ret) {
	if (!_pendingNodes.empty()) {
		ret.clear();
		ret.reserve(_pendingNodes.size());
		for (auto v : _pendingNodes){
			ret.push_back(v);
		}
	}
}

bool TestSelector::Iterator(int index) {
	if (index >= _namedLists.size()) {
		OutputDebugString(L"index >= _namedLists.size()");
		return false;
	}
	std::wstring& currentName = _namedLists[index];
	if (currentName.empty()) {
		OutputDebugString(L"currentName.empty()");
		return false;
	}

	if (_pendingNodes.empty()) {
		OutputDebugString(L"_pendingNodes.empty()");
		return false;
	}

	if (currentName[0] == '#') {
		//#id
		CefRefPtr<CefDOMNode> node = _pendingNodes.front()->GetDocument()->GetElementById(&currentName[1]);
		if (!node) {
			return false;
		}
		_resultNodes.push_back(node);
		OutputDebugString(L"GetElementById Finded!!!");
	}
	else if (currentName == L"*") {
		//*
		FetchAll();
	}
	else if (currentName[0] == '.') {
		//.class

		OutputDebugString(L".class !!!");
		OutputDebugString(currentName.c_str());

		FetchByClass(&currentName[1]);

		OutputDebugString(currentName.c_str());
		OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
		OutputDebugString(L".class Finded!!!");
	}
	else if (currentName[0] == '[' && currentName[currentName.length() - 1] == ']') {
		FetchAttributes(currentName);
	}
	else if (currentName == L":first-child") {
		FetchFirstChild();
	}
	else if (currentName == L":last-child") {
		FetchLastChild();
	}
	else if (currentName == L":only-child") {
		FetchOnlyChild();
	}
	else if (wcsncmp(&currentName[0], L":nth-child",10) == 0) {
		FetchNthChild(currentName);
	}
	else if (wcsncmp(&currentName[0], L":nth-last-child", 15) == 0) {
		FetchNthLastChild(currentName);
	}
	else if (currentName == L":first-of-type") {
		FetchFirstOfType();
	}
	else if (currentName == L":last-of-type") {
		FetchLastOfType();
	}
	else if (currentName == L":only-of-type") {
		FetchOnlyOfType();
	}
	else if (wcsncmp(&currentName[0], L":nth-of-type", 12) == 0) {
		FetchNthOfType(currentName);
	}
	else if (wcsncmp(&currentName[0], L":nth-last-of-type", 17) == 0) {
		FetchNthLastOfType(currentName);
	}
	else if(currentName != L">") {
		if (FetchElements(currentName)) {
			_pendingNodes.clear();
			_pendingNodes = _resultNodes;
			_resultNodes.clear();
			OutputDebugString(L"element:attribute!!");
			return false;
		}
	}
	else {
		OutputDebugString(L"xxxxxx");
		OutputDebugString(std::to_wstring(_pendingNodes.size()).c_str());
		return false;
	}

	//////////////////////////////////////////
	////////////////////////////////////////////////////////////
	NextIterator(index);
	return false;
}

void TestSelector::FetchAll() {
	for (auto v : _pendingNodes){
		FetchChild(v);
	}
}

void TestSelector::FetchChild(CefRefPtr<CefDOMNode> node) {
	if (!node) return;
	_resultNodes.push_back(node);
	CefRefPtr<CefDOMNode> child = node->GetFirstChild();
	while (child){
		FetchChild(child);
		child = child->GetNextSibling();
	}
}

void TestSelector::FetchByClass(const wchar_t* className) {
	std::wstring convert_classname = className;
	size_t length = lstrlenW(className);
	for (size_t i = 0; i < convert_classname.size(); i++){
		if (convert_classname[i] == '.') {
			convert_classname[i] = ' ';
		}
	}
	for (auto v : _pendingNodes) {
		FetchChildByClass(v, convert_classname.c_str());
	}
}

void TestSelector::FetchChildByClass(CefRefPtr<CefDOMNode> node, const wchar_t* className) {
	if (!node) return;
	if (node->HasElementAttributes() && node->HasElementAttribute(L"class")) {
		CefString attrib = node->GetElementAttribute(L"class");
		if (!attrib.empty() && _tcsstr(attrib.c_str(), className)) {
			_resultNodes.push_back(node);
		}
	}
	CefRefPtr<CefDOMNode> child = node->GetFirstChild();
	while (child) {
		FetchChildByClass(child, className);
		child = child->GetNextSibling();
	}
}

void TestSelector::FetchByAttrib(const wchar_t* attribName) {
	const wchar_t* method1 = _tcsstr(attribName,L"~=");
	const wchar_t* method2 = !method1 ? _tcsstr(attribName, L"|=") : nullptr;
	const wchar_t* method3 = !method2 ? _tcsstr(attribName, L"^=") : nullptr;
	const wchar_t* method4 = !method3 ? _tcsstr(attribName, L"$=") : nullptr;
	const wchar_t* method5 = !method4 ? _tcsstr(attribName, L"*=") : nullptr;
	const wchar_t* method6 = !method5 ? _tcsstr(attribName, L"=") : nullptr;
	std::wstring name, value;

	int oper = 0;
	if (method1) {
		oper = 1;
		name.assign(attribName, method1);

		size_t length = lstrlenW(&method1[2]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++){
			if (method1[2+i] != '\"') {
				value.push_back(method1[2 + i]);
			}
		}
	}
	else if (method2) {
		oper = 2;
		name.assign(attribName, method2);
		
		size_t length = lstrlenW(&method2[2]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++) {
			if (method2[2 + i] != '\"') {
				value.push_back(method2[2 + i]);
			}
		}
	}
	else if (method3) {
		oper = 3;
		name.assign(attribName, method3);
		
		size_t length = lstrlenW(&method3[2]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++) {
			if (method3[2 + i] != '\"') {
				value.push_back(method3[2 + i]);
			}
		}
	}
	else if (method4) {
		oper = 4;
		name.assign(attribName, method4);

		size_t length = lstrlenW(&method4[2]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++) {
			if (method4[2 + i] != '\"') {
				value.push_back(method4[2 + i]);
			}
		}
	}
	else if (method5) {
		oper = 5;
		name.assign(attribName, method5);
		
		size_t length = lstrlenW(&method5[2]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++) {
			if (method5[2 + i] != '\"') {
				value.push_back(method5[2 + i]);
			}
		}
	}
	else if (method6) {
		oper = 6;
		name.assign(attribName, method6);
		
		size_t length = lstrlenW(&method6[1]);
		value.reserve(length);
		for (size_t i = 0; i < length; i++) {
			if (method6[1 + i] != '\"') {
				value.push_back(method6[1 + i]);
			}
		}
	}
	else {
		name.assign(attribName);
	}
	for (auto v: _pendingNodes){
		FetchChildByAttrib(v, name, value, oper);
	}
}

void TestSelector::FetchChildByAttrib(CefRefPtr<CefDOMNode> node, const std::wstring& name, const std::wstring& value, int method) {
	if (!node) return;
	if (node->HasElementAttribute(name)) {
		if (method == 0) { 
			// [target] 选择带有 target 属性所有元素。

			_resultNodes.push_back(node);
		}
		else if (method == 1 || method == 5) { 
			//[title~=flower] 选择 title 属性包含单词 "flower" 的所有元素。
			//a[src*="abc"] 选择其 src 属性中包含 "abc" 子串的每个 <a> 元素。

			CefString attrib_value;

			if (name == L"type") {
				if (node->IsFormControlElement()) {
					attrib_value = node->GetFormControlElementType();
				}
				else {
					attrib_value = node->GetElementAttribute(name);
				}
			}
			else {
				attrib_value = node->GetElementAttribute(name);
			}
			
			if (!attrib_value.empty() && _tcsstr(attrib_value.c_str(), value.c_str())) {
				_resultNodes.push_back(node);
			}
		}
		else if (method == 2 || method == 3) {
			//[lang|=en] 选择 lang 属性值以 "en" 开头的所有元素。
			//a[src^="https"] 选择其 src 属性值以 "https" 开头的每个 <a> 元素。

			CefString attrib_value;

			if (name == L"type") {
				if (node->IsFormControlElement()) {
					attrib_value = node->GetFormControlElementType();
				}
				else {
					attrib_value = node->GetElementAttribute(name);
				}
			}
			else {
				attrib_value = node->GetElementAttribute(name);
			}

			if (!attrib_value.empty() && wcsncmp(value.c_str(), attrib_value.c_str(), value.length()) == 0) {
				_resultNodes.push_back(node);
			}
		}
		else if (method == 4) {
			//	a[src$=".pdf"] 选择其 src 属性以 ".pdf" 结尾的所有 <a> 元素。
			CefString attrib_value;

			if (name == L"type") {
				if (node->IsFormControlElement()) {
					attrib_value = node->GetFormControlElementType();
				}
				else {
					attrib_value = node->GetElementAttribute(name);
				}
			}
			else {
				attrib_value = node->GetElementAttribute(name);
			}

			if (attrib_value.length() >= value.length()) {
				const wchar_t* vsrc = attrib_value.c_str();
				if (wcsncmp(&vsrc[attrib_value.length() - value.length()], value.c_str(),value.length()) == 0) {
					_resultNodes.push_back(node);
				}
			}
		}
		else if (method == 6) {
			CefString attrib_value;

			if (name == L"type") {
				OutputDebugString(L"xxx name = type xxxx");
				if (node->IsFormControlElement()) {
					attrib_value = node->GetFormControlElementType();
					OutputDebugString(attrib_value.c_str());
				}
				else {
					attrib_value = node->GetElementAttribute(name);
				}
			}
			else {
				attrib_value = node->GetElementAttribute(name);
			}

			OutputDebugString(L"xxx find xxxx");
			OutputDebugString(attrib_value.c_str());
			OutputDebugString(value.c_str());
			if (!attrib_value.empty() && attrib_value == value) {
				
				_resultNodes.push_back(node);
			}
		}
	}
	CefRefPtr<CefDOMNode> child = node->GetFirstChild();
	while (child) {
		FetchChildByAttrib(child, name, value, method);
		child = child->GetNextSibling();
	}
}

void TestSelector::FetchByTag(std::vector<std::wstring>& tags, int method) {
	if (tags.empty()) {
		return;
	}
	for (auto v: _pendingNodes){
		FetchChildByTag(v, tags,method);
	}
}

void TestSelector::FetchChildByTag(CefRefPtr<CefDOMNode> node, std::vector<std::wstring>& tags, int method) {
	if (!node) return;
	std::wstring name = node->GetElementTagName().ToWString();
	for (size_t i = 0; i < name.size(); i++){
		name[i] = std::tolower(name[i]);
	}
	if (method == 0) { //element,element	div,p	选择所有 <div> 元素和所有 <p> 元素。
		for (auto v : tags) {
			if (v == name) {
				_resultNodes.push_back(node);
				break;
			}
		}
	}
	else if (method == 1) {//element+element	div+p	选择紧接在 <div> 元素之后的所有 <p> 元素。
		CefRefPtr<CefDOMNode> temp = nullptr;
		if (tags[0] == name) {
			CefRefPtr<CefDOMNode> sibling = node->GetNextSibling();
			CefString sib_tag;
			while (sibling) {
				sib_tag = sibling->GetElementTagName();
				if (!sib_tag.empty()) {
					name = sib_tag.ToWString();
					for (size_t i = 0; i < name.size(); i++) {
						name[i] = std::tolower(name[i]);
					}
					if (name == tags[1]) {
						_resultNodes.push_back(node);
					}
					break;
				}
				sibling = sibling->GetNextSibling();
			}

		}
	}
	else if (method == 2) {//element1~element2	p~ul	选择前面有 <p> 元素的每个 <ul> 元素。
		if (name == tags[1]) {
			CefRefPtr<CefDOMNode> sibling = node->GetPreviousSibling();
			CefString sib_tag;
			while (sibling){
				sib_tag = sibling->GetElementTagName();
				if (!sib_tag.empty()) {
					name = sib_tag.ToWString();
					for (size_t i = 0; i < name.size(); i++) {
						name[i] = std::tolower(name[i]);
					}
					if (name == tags[0]) {
						_resultNodes.push_back(node);
						break;
					}
					
				}
				sibling = sibling->GetPreviousSibling();
			}
		}
	}
	else if (method == 3) {//element1>element2	选取父元素是 <div> 元素的每个 <p> 元素，并设置其背景色：
		if (name == tags[1]) {
			CefRefPtr<CefDOMNode> temp = node->GetParent();
			name = temp->GetElementTagName().ToWString();
			for (size_t i = 0; i < name.size(); i++) {
				name[i] = std::tolower(name[i]);
			}
			if (temp && name == tags[0]) {
				_resultNodes.push_back(node);
			}
		}
	}
	else if (method == 4) { // element
		//int index = _curIndex - 2;
		//if (index >= 0 && index < _namedLists.size()) {
		//	if (_namedLists[index+1] == L">") {
		//		tags.insert(tags.begin(), _namedLists[index]);
		//		FetchChildByTag(node, tags, 3);
		//		return;
		//	}
		//}

		if (name == tags[0]) {
			_resultNodes.push_back(node);
		}
	}
	CefRefPtr<CefDOMNode> child = node->GetFirstChild();
	while (child) {
		FetchChildByTag(child, tags,method);
		child = child->GetNextSibling();
	}
}

void TestSelector::FetchAttributes(const std::wstring& currentName) {
	std::wstring attrib = currentName.substr(1, currentName.length() - 2);
	FetchByAttrib(attrib.c_str());

	OutputDebugString(currentName.c_str());
	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L"[attribute] Finded!!!");
}

void TestSelector::FetchFirstChild() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> child = nullptr;

	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			child = this->GetFirstChild(parent);
			if (child->IsSame(v)) {
				_resultNodes.push_back(v);
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":first-child Finded!!!");
}

void TestSelector::FetchLastChild() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> child = nullptr;

	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			child = this->GetLastChild(parent);
			if (child->IsSame(v)) {
				_resultNodes.push_back(v);
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":last-child Finded!!!");
}

void TestSelector::FetchOnlyChild() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> first = nullptr;
	CefRefPtr<CefDOMNode> last = nullptr;

	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			first = this->GetFirstChild(parent);
			last = this->GetLastChild(parent);
			if (first && last && first->IsSame(last) && first->IsSame(v)) {
				_resultNodes.push_back(v);
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":only-child Finded!!!");
}

void TestSelector::FetchNthChild(const std::wstring& currentName) {
	std::wstring str_skip = currentName.substr(11, currentName.length() - 12);
	int skip = _wtol(str_skip.c_str());
	if (skip > 0) {
		CefRefPtr<CefDOMNode> parent = nullptr;
		CefRefPtr<CefDOMNode> child = nullptr;
		CefString tag;
		skip--;

		for (auto v : _pendingNodes) {
			parent = v->GetParent();
			if (parent) {
				int count = 0;
				child = parent->GetFirstChild();
				while (child)
				{
					tag = child->GetElementTagName();
					if (!tag.empty()) {
						if (count == skip) {
							if (child->IsSame(v)) {
								_resultNodes.push_back(v);
								break;
							}
						}
						count++;
					}
					child = child->GetNextSibling();
				}
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":nth-child Finded!!!");
}

void TestSelector::FetchNthLastChild(const std::wstring& currentName) {
	std::wstring str_skip = currentName.substr(16, currentName.length() - 17);
	int skip = _wtol(str_skip.c_str());
	if (skip > 0) {
		CefRefPtr<CefDOMNode> parent = nullptr;
		CefRefPtr<CefDOMNode> child = nullptr;
		CefString tag;
		skip--;

		for (auto v : _pendingNodes) {
			parent = v->GetParent();
			if (parent) {
				int count = 0;
				child = parent->GetLastChild();
				while (child)
				{
					tag = child->GetElementTagName();
					if (!tag.empty()) {
						if (count == skip) {
							if (child->IsSame(v)) {
								_resultNodes.push_back(v);
								break;
							}
						}
						count++;
					}
					child = child->GetPreviousSibling();
				}
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":nth-last-child Finded!!!");
}

CefRefPtr<CefDOMNode> TestSelector::GetFirstChild(CefRefPtr<CefDOMNode> node) {
	CefString tag;
	CefRefPtr<CefDOMNode> child = nullptr;

	if (!node) return nullptr;

	child = node->GetFirstChild();
	while (child){
		tag = child->GetElementTagName();
		if (!tag.empty()) return child;
		child = child->GetNextSibling();
	}

	return nullptr;
}

CefRefPtr<CefDOMNode> TestSelector::GetLastChild(CefRefPtr<CefDOMNode> node) {
	CefString tag;
	CefRefPtr<CefDOMNode> child = nullptr;

	if (!node) return nullptr;

	child = node->GetLastChild();
	while (child) {
		tag = child->GetElementTagName();
		if (!tag.empty()) return child;
		child = child->GetPreviousSibling();
	}

	return nullptr;
}

void TestSelector::FetchFirstOfType() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> child = nullptr;
	CefString tag;
	CefString mytag;
	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			mytag = v->GetElementTagName();
			child = parent->GetFirstChild();
			while (child){
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					if (tag == mytag) {
						if (child->IsSame(v)) {
							_resultNodes.push_back(v);
						}
						break;
					}
				}
				child = child->GetNextSibling();
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":first-of-type Finded!!!");
}

void TestSelector::FetchLastOfType() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> child = nullptr;
	CefString tag;
	CefString mytag;
	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			mytag = v->GetElementTagName();
			child = parent->GetLastChild();
			while (child) {
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					if (tag == mytag) {
						if (child->IsSame(v)) {
							_resultNodes.push_back(v);
						}
						break;
					}
				}
				child = child->GetPreviousSibling();
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":last-of-type Finded!!!");
}

void TestSelector::FetchOnlyOfType() {
	CefRefPtr<CefDOMNode> parent = nullptr;
	CefRefPtr<CefDOMNode> child = nullptr;
	CefRefPtr<CefDOMNode> first = nullptr;
	CefRefPtr<CefDOMNode> last = nullptr;
	CefString tag;
	CefString mytag;
	for (auto v : _pendingNodes) {
		parent = v->GetParent();
		if (parent) {
			mytag = v->GetElementTagName();
			child = parent->GetFirstChild();
			while (child) {
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					if (tag == mytag) {
						if (!first) {
							first = child;
						}
						last = child;
					}
				}
				child = child->GetNextSibling();
			}

			if (first && last && first->IsSame(last) && first->IsSame(v)) {
				_resultNodes.push_back(v);
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":only-of-type Finded!!!");
}

void TestSelector::FetchNthOfType(const std::wstring& currentName) {
	std::wstring str_skip = currentName.substr(13, currentName.length() - 14);
	int skip = _wtol(str_skip.c_str());
	if (skip > 0) {
		CefRefPtr<CefDOMNode> parent = nullptr;
		CefRefPtr<CefDOMNode> child = nullptr;
		CefString tag;
		CefString mytag;

		skip--;

		for (auto v : _pendingNodes) {
			parent = v->GetParent();
			if (parent) {
				mytag = v->GetElementTagName();
				child = parent->GetFirstChild();
				int count = 0;

				while (child) {
					tag = child->GetElementTagName();
					if (!tag.empty()) {
						if (tag == mytag) {
							if (count == skip) {
								if (child->IsSame(v)) {
									_resultNodes.push_back(v);
									break;
								}
							}
							count++;
						}
					}
					child = child->GetNextSibling();
				}
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":nth-of-type Finded!!!");
}

void TestSelector::FetchNthLastOfType(const std::wstring& currentName) {
	std::wstring str_skip = currentName.substr(18, currentName.length() - 19);
	int skip = _wtol(str_skip.c_str());
	if (skip > 0) {
		CefRefPtr<CefDOMNode> parent = nullptr;
		CefRefPtr<CefDOMNode> child = nullptr;
		CefString tag;
		CefString mytag;

		skip--;

		for (auto v : _pendingNodes) {
			parent = v->GetParent();
			if (parent) {
				mytag = v->GetElementTagName();
				child = parent->GetLastChild();
				int count = 0;

				while (child) {
					tag = child->GetElementTagName();
					if (!tag.empty()) {
						if (tag == mytag) {
							if (count == skip) {
								if (child->IsSame(v)) {
									_resultNodes.push_back(v);
									break;
								}
							}
							count++;
						}
					}
					child = child->GetPreviousSibling();
				}
			}
		}
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(L":nth-last-of-type Finded!!!");
}

bool TestSelector::FetchElements(const std::wstring& currentName) {
	size_t begin = 0;
	std::wstring tag_name;
	std::vector<std::wstring> tags;
	bool has_desc = false;
	tag_name.reserve(currentName.length());
	int index = _curIndex;

	for (size_t i = 0; i < currentName.length(); i++) {
		if (currentName[i] == '[' || currentName[i] == ':' || currentName[i] == '.') {
			if ((index + 1) >= _namedLists.size()) {
				_namedLists.push_back(&currentName[i]);
			}
			else {
				_namedLists.insert(_namedLists.begin() + index + 1, &currentName[i]);
			}
			has_desc = true;
			break;
		}
		tag_name.push_back(currentName[i]);
	}

	if (tag_name.find(L",") != std::wstring::npos) {
		SplitString(tag_name, L",", tags);
		FetchByTag(tags, 0);
	}
	else if (tag_name.find(L"+") != std::wstring::npos) {
		SplitString(tag_name, L"+", tags);
		FetchByTag(tags, 1);
	}
	else if (tag_name.find(L"~") != std::wstring::npos) {
		SplitString(tag_name, L"~", tags);
		FetchByTag(tags, 2);
	}
	else if (tag_name.find(L">") != std::wstring::npos) {
		SplitString(tag_name, L">", tags);
		FetchByTag(tags, 3);
	}
	else {
		tags.push_back(tag_name);
		OutputDebugString(L"element xxxx");
		FetchByTag(tags, 4);
	}

	OutputDebugString(std::to_wstring(_resultNodes.size()).c_str());
	OutputDebugString(tag_name.c_str());
	OutputDebugString(L"tag Finded!!!");
	OutputDebugString(L"===================!!!");

	return has_desc;
}

void TestSelector::NextIterator(int index) {
	CefRefPtr<CefDOMNode> child = nullptr;
	CefString tag;

	if ((index + 1) >= _namedLists.size()) {
		_pendingNodes.clear();
		for (auto v : _resultNodes) {
			tag = v->GetElementTagName();
			if (!tag.empty()) {
				_pendingNodes.push_back(v);
			}
		}
	}
	else {

		_pendingNodes.clear();
		for (auto v : _resultNodes) {
			child = v->GetFirstChild();
			while (child) {
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					_pendingNodes.push_back(child);
				}
				child = child->GetNextSibling();
			}
		}
		_resultNodes.clear();

	}
}