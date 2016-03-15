// 下列 ifdef 區塊是建立巨集以協助從 DLL 匯出的標準方式。
// 這個 DLL 中的所有檔案都是使用命令列中所定義 CRACKCODEINTERVIEWDLL_EXPORTS 符號編譯的。
// 在命令列定義的符號。任何專案都不應定義這個符號
// 這樣一來，原始程式檔中包含這檔案的任何其他專案
// 會將 CRACKCODEINTERVIEWDLL_API 函式視為從 DLL 匯入的，而這個 DLL 則會將這些符號視為
// 匯出的。
#ifdef CRACKCODEINTERVIEWDLL_EXPORTS
#define CRACKCODEINTERVIEWDLL_API __declspec(dllexport)
#else
#define CRACKCODEINTERVIEWDLL_API __declspec(dllimport)
#endif

#include "LinkedList.h"

// 這個類別是從 CrackCodeInterviewDll.dll 匯出的
class CRACKCODEINTERVIEWDLL_API CCrackCodeInterviewDll {
public:
	CCrackCodeInterviewDll(void);
	bool hasUniqueChar(char* str, size_t size);
	void reverse(char* str);
	bool isPermutated(char* str, char* permutatedStr);

	//Chapter 2
	void removeDuplicate(LinkedList list);
	Node* getKthLast(LinkedList list, unsigned int k);
	void deleteMiddle(LinkedList list, Node* pMid);
	void partitionValue(LinkedList& list, int x);
};

extern CRACKCODEINTERVIEWDLL_API int nCrackCodeInterviewDll;

CRACKCODEINTERVIEWDLL_API int fnCrackCodeInterviewDll(void);
