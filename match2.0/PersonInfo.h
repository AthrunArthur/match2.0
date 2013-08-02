#ifndef PERSON_INFO_H_
#define PERSON_INFO_H_
#include <vector>
#include <map>
#include <memory>
#include <string>


class PersonInfo;
typedef std::shared_ptr<PersonInfo> PersonInfoPtr;
typedef std::vector<PersonInfoPtr> PersonGroup;
typedef std::shared_ptr<PersonGroup> PersonGroupPtr;
typedef std::map<PersonInfoPtr,PersonGroupPtr>	MapGB;	//���Ů�Ժ�ѡ����Ϣ����Ů��ͶƱ�������ԣ�
typedef std::pair<PersonInfoPtr, PersonInfoPtr> BGPair; //<Boy, Girl>
typedef std::vector<BGPair>	 BGPairs;
typedef std::shared_ptr<BGPairs>	BGPairsPtr;


class PersonInfo
{
public:
	PersonInfo();
	PersonInfo(int uid, int iwealth, int ilook, int icharactor, int ihealth, int rwealth, int rlook, int rcharactor, int rhealth, int igender, int mixExpertation);
	
	int		sumOfInfo();
	int		getSatDegree(PersonInfoPtr p);		//����һ���˶���һ���˵������
	int		getPersonGenger();
	int		getUsrid();
	
	PersonInfoPtr 	selectTheBestOne(PersonGroupPtr group);	//ѡ����һ�Ա��������������
	PersonInfoPtr	selectSatBiggerThanExp(PersonGroupPtr group);	//���Ժ�ѡ���н���������ȴ��ڵ���Ů��������1.5������ѡ�������
	int				isNoBestOne(PersonGroupPtr group);	//�Ƿ����Ժ�ѡ�˵���������ȶ�С��Ů������ֵ
	PersonGroupPtr	selectMaxSatDegree(PersonGroupPtr group);
	static	PersonGroupPtr	selectMaxSum(PersonGroupPtr group);
	static	PersonInfoPtr	selectMinId(PersonGroupPtr group);
	
	
	static PersonGroupPtr	readFromFile(const std::string & file);	//���ļ��ж�ȡ�û���Ϣ
	static PersonGroupPtr	generateRandomPersons(int num, int gender);	//���������Ϣ���û���numΪ������ĸ�����genderΪ�Ա�
	static PersonInfoPtr	generateOnePerson(int id, int gender);

	static void			showPairs(BGPairsPtr ps);
	static void			dumpPairsToFile(BGPairsPtr ps, const std::string & file);
	
protected:
	int m_userID;
	int m_info_wealth;		//��������
	int m_info_look;		
	int m_info_charactor;	
	int m_info_health;		
	int m_ratio_wealth;
	int m_ratio_look;
	int m_ratio_charactor;
	int m_ratio_health;		//����ż����ָ��������ٷֱȣ����ߺ�Ϊ100������ȡֵ1~97
	int m_gender;			//1:male; 0:female
	int m_mixExpertation;	//����������ȵ��������ֵ( �����û���Ϊ0 ��
};//end class PersonInfo;
#endif