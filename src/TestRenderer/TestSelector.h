#pragma once
#include "include/cef_dom.h"
#include <vector>
#include <string>
#include <list>

class TestSelector {
public:
	TestSelector(CefRefPtr<CefDOMNode> node, const CefString& selectors, bool once);
	~TestSelector();

public:
	bool Find(void);

	CefRefPtr<CefDOMNode> GetFirstElement();

	void GetAllElement(std::vector<CefRefPtr<CefDOMNode>>& ret);

private:
	bool Iterator(int index);

private:
	void SplitPath(const CefString& s);

	int SplitString(const std::wstring& s, const std::wstring& p, std::vector<std::wstring>& ret);

private:
	// *
	void FetchAll();

	void FetchChild(CefRefPtr<CefDOMNode> node);

private:
	// .class
	void FetchByClass(const wchar_t* className);

	void FetchChildByClass(CefRefPtr<CefDOMNode> node, const wchar_t* className);

private:
	// []
	void FetchByAttrib(const wchar_t* attribName);

	void FetchChildByAttrib(CefRefPtr<CefDOMNode> node, const std::wstring& name, const std::wstring& value, int method);

private:
	// element,element
	void FetchByTag(std::vector<std::wstring>& tags, int method);

	void FetchChildByTag(CefRefPtr<CefDOMNode> node, std::vector<std::wstring>& tags, int method);

private:
	void FetchAttributes(const std::wstring& currentName);

	bool FetchElements(const std::wstring& currentName);

private:
	void FetchFirstChild();

	void FetchLastChild();

	void FetchOnlyChild();

	void FetchNthChild(const std::wstring& currentName);

	void FetchNthLastChild(const std::wstring& currentName);

private:
	void FetchFirstOfType();

	void FetchLastOfType();

	void FetchOnlyOfType();

	void FetchNthOfType(const std::wstring& currentName);

	void FetchNthLastOfType(const std::wstring& currentName);
private:
	CefRefPtr<CefDOMNode> GetFirstChild(CefRefPtr<CefDOMNode> node);

	CefRefPtr<CefDOMNode> GetLastChild(CefRefPtr<CefDOMNode> node);


private:
	void NextIterator(int index);

private:
	CefRefPtr<CefDOMNode> _rootNode;
	std::list<CefRefPtr<CefDOMNode>> _resultNodes;
	std::vector<std::wstring> _namedLists;
	std::list<CefRefPtr<CefDOMNode>> _pendingNodes;
	int _curIndex;
};

