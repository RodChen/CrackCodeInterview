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

// �o�����O�O�q CrackCodeInterviewDll.dll �ץX��
class CRACKCODEINTERVIEWDLL_API CCrackCodeInterviewDll {
public:
	CCrackCodeInterviewDll(void);
	// TODO:  �b���[�J�z����k�C
	void reverse(char* str);
};

extern CRACKCODEINTERVIEWDLL_API int nCrackCodeInterviewDll;

CRACKCODEINTERVIEWDLL_API int fnCrackCodeInterviewDll(void);
