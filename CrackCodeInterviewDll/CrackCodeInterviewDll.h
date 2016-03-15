// �U�C ifdef �϶��O�إߥ����H��U�q DLL �ץX���зǤ覡�C
// �o�� DLL �����Ҧ��ɮ׳��O�ϥΩR�O�C���ҩw�q CRACKCODEINTERVIEWDLL_EXPORTS �Ÿ��sĶ���C
// �b�R�O�C�w�q���Ÿ��C����M�׳������w�q�o�ӲŸ�
// �o�ˤ@�ӡA��l�{���ɤ��]�t�o�ɮת������L�M��
// �|�N CRACKCODEINTERVIEWDLL_API �禡�����q DLL �פJ���A�ӳo�� DLL �h�|�N�o�ǲŸ�����
// �ץX���C
#ifdef CRACKCODEINTERVIEWDLL_EXPORTS
#define CRACKCODEINTERVIEWDLL_API __declspec(dllexport)
#else
#define CRACKCODEINTERVIEWDLL_API __declspec(dllimport)
#endif

#include "LinkedList.h"

// �o�����O�O�q CrackCodeInterviewDll.dll �ץX��
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
