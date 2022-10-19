/**
* @brief	�N�C�b�N�\�[�g�̃e�X�g
* @date		2022/10/13
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../StackQueue/LinkedList.h"
#include "ScoreData.h"
#include "TestHelper.h"
#include <vector>
#include <algorithm>

//===== ���O��� =====
/**
* @brief	�N�C�b�N�\�[�g�̃e�X�g�p���O���
*/
namespace ex03_Quicksort
{

//===== �\���̒�` =====
/**
* @brief	���肵���\�[�g�łȂ����Ƃ��m�F���邽�߂̍\����
*/
struct ScoreData_US : public ScoreData
{
	int Element;	// �v�f�ԍ�

	ScoreData_US() = default;

	ScoreData_US(int Score_, const std::string& Name_, int Element_)
		: Element(Element_)
	{
		Score = Score_;
		Name = Name_;
	}
};

//===== �N���X��` =====
/**
* @brief	ScoreData���X�R�A�� > ��r���邽�߂̊֐��I�u�W�F�N�g 
*/
class CompareFuncScoreGreater
{
public:

	/**
	* @brief		ScoreData���X�R�A�� > ��r����
	* @param[in]	Left	��r����f�[�^1
	* @param[in]	Right	��r����f�[�^2
	* @retval		true	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A���傫����
	* @retval		false	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A��菬������
	*/
	bool operator() (const ScoreData& Left, const ScoreData& Right)
	{
		return Left.Score > Right.Score;
	}

	/**
	* @brief		ScoreData���X�R�A�� > ��r����(qsort�p)
	* @param[in]	pLeft	��r����f�[�^1
	* @param[in]	pRight	��r����f�[�^2
	* @retval		-1	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A���傫����
	* @retval		0	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A�Ɠ�����
	* @retval		1	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A��菬������
	*/
	static int Comp(const void* pLeft, const void* pRight)
	{
		const ScoreData* Left  = static_cast<const ScoreData*>(pLeft);
		const ScoreData* Right = static_cast<const ScoreData*>(pRight);

		if (Left->Score > Right->Score)
			return -1;

		if (Left->Score == Right->Score)
			return 0;

		if (Left->Score < Right->Score)
			return 1;

		return 0;
	}
};

/**
* @brief	ScoreData���X�R�A�� < ��r���邽�߂̊֐��I�u�W�F�N�g
*/
class CompareFuncScoreLess
{
public:

	/**
	* @brief		ScoreData���X�R�A�� < ��r����
	* @param[in]	Left	��r����f�[�^1
	* @param[in]	Right	��r����f�[�^2
	* @retval		true	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A��菬������
	* @retval		false	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A���傫����
	*/
	bool operator() (const ScoreData& Left, const ScoreData& Right)
	{
		return Left.Score < Right.Score;
	}

	/**
	* @brief		ScoreData���X�R�A�� < ��r����(qsort�p)
	* @param[in]	pLeft	��r����f�[�^1
	* @param[in]	pRight	��r����f�[�^2
	* @retval		-1	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A��菬������
	* @retval		0	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A�Ɠ�����
	* @retval		1	�f�[�^1�̃X�R�A���f�[�^2�̃X�R�A���傫����
	*/
	static int Comp(const void* pLeft, const void* pRight)
	{
		if (!pLeft || !pRight)
			return 0;

		const ScoreData* Left = static_cast<const ScoreData*>(pLeft);
		const ScoreData* Right = static_cast<const ScoreData*>(pRight);

		if (Left->Score < Right->Score)
			return -1;

		if (Left->Score == Right->Score)
			return 0;

		if (Left->Score > Right->Score)
			return 1;

		return 0;
	}
};

/**
* @brief	ScoreData�����[�U�[���� > ��r���邽�߂̊֐��I�u�W�F�N�g
*/
class CompareFuncNameGreater
{
public:

	/**
	* @brief		ScoreData�𖼑O�� > ��r����
	* @param[in]	Left	��r����f�[�^1
	* @param[in]	Right	��r����f�[�^2
	* @retval		true	�f�[�^1�̖��O���f�[�^2�̖��O���傫��(�����R�[�h�I�Ɍ��)�̎�
	* @retval		false	�f�[�^1�̖��O���f�[�^2�̖��O��菬����(�����R�[�h�I�ɑO)�̎�
	*/
	bool operator() (const ScoreData& Left, const ScoreData& Right)
	{
		return Left.Name > Right.Name;
	}

	/**
	* @brief		ScoreData�𖼑O�� > ��r����(qsort�p)
	* @param[in]	pLeft	��r����f�[�^1
	* @param[in]	pRight	��r����f�[�^2
	* @retval		-1	�f�[�^1�̖��O���f�[�^2�̖��O���傫��(�����R�[�h�I�Ɍ��)�̎�
	* @retval		0	�f�[�^1�̖��O���f�[�^2�̖��O�Ɠ�����
	* @retval		1	�f�[�^1�̖��O���f�[�^2�̖��O��菬����(�����R�[�h�I�ɑO)�̎�
	*/
	static int Comp(const void* pLeft, const void* pRight)
	{
		if (!pLeft || !pRight)
			return 0;

		const ScoreData* Left = static_cast<const ScoreData*>(pLeft);
		const ScoreData* Right = static_cast<const ScoreData*>(pRight);

		if (Left->Name > Right->Name)
			return -1;

		if (Left->Name == Right->Name)
			return 0;

		if (Left->Name < Right->Name)
			return 1;

		return 0;
	}
};

/**
* @brief	ScoreData�����[�U�[���� < ��r���邽�߂̊֐��I�u�W�F�N�g
*/
class CompareFuncNameLess
{
public:

	/**
	* @brief		ScoreData�𖼑O�� < ��r����
	* @param[in]	Left	��r����f�[�^1
	* @param[in]	Right	��r����f�[�^2
	* @retval		true	�f�[�^1�̖��O���f�[�^2�̖��O��菬����(�����R�[�h�I�ɑO)�̎�
	* @retval		false	�f�[�^1�̖��O���f�[�^2�̖��O���傫��(�����R�[�h�I�Ɍ��)�̎�
	*/
	bool operator() (const ScoreData& Left, const ScoreData& Right)
	{
		return Left.Name < Right.Name;
	}

	/**
	* @brief		ScoreData�𖼑O�� < ��r����(qsort�p)
	* @param[in]	pLeft	��r����f�[�^1
	* @param[in]	pRight	��r����f�[�^2
	* @retval		-1	�f�[�^1�̖��O���f�[�^2�̖��O��菬����(�����R�[�h�I�ɑO)�̎�
	* @retval		0	�f�[�^1�̖��O���f�[�^2�̖��O�Ɠ�����
	* @retval		1	�f�[�^1�̖��O���f�[�^2�̖��O���傫��(�����R�[�h�I�Ɍ��)�̎�
	*/
	static int Comp(const void* pLeft, const void* pRight)
	{
		if (!pLeft || !pRight)
			return 0;

		const ScoreData* Left = static_cast<const ScoreData*>(pLeft);
		const ScoreData* Right = static_cast<const ScoreData*>(pRight);

		if (Left->Name < Right->Name)
			return -1;

		if (Left->Name == Right->Name)
			return 0;

		if (Left->Name > Right->Name)
			return 1;

		return 0;
	}
};

/**
* @brief	�^�t���e�X�g�p�̃N���X
*/
template<class T>
class QuicksortTest : public ::testing::Test
{
};

//===== �^�G�C���A�X =====
using DistanceF = LinkedListTestFixture;	// Distance()�p�t�B�N�X�`��

typedef ::testing::Types<CompareFuncScoreGreater, CompareFuncScoreLess, CompareFuncNameGreater, CompareFuncNameLess> CompFuncs;
TYPED_TEST_CASE(QuicksortTest, CompFuncs);

#pragma region ***** �N�C�b�N�\�[�g *****

/**
* @brief	�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
* @details	ID:0
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			�v�f�������Ȃ����X�g�ɑ΂��ă\�[�g���s�������A�����N����Ȃ����Ƃ��m�F���܂��B
*			�v�f����0�̂܂܁A�擪�C�e���[�^ == �����C�e���[�^ �̎������藧�Ăΐ����Ƃ��܂��B
*/
TYPED_TEST(QuicksortTest, NoItem)
{
	LinkedList<ScoreData> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�
	
	// �\�[�g�O�ɃT�C�Y�ƃC�e���[�^���`�F�b�N
	EXPECT_EQ(0, List.GetSize());
	EXPECT_TRUE(List.GetConstBegin() == List.GetConstEnd());

	// �\�[�g
	List.Quicksort(Comp);

	// �T�C�Y�ƃC�e���[�^���`�F�b�N
	EXPECT_EQ(0, List.GetSize());
	EXPECT_TRUE(List.GetConstBegin() == List.GetConstEnd());
}

/**
* @brief	�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
* @details	ID:1
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			�v�f��1���������X�g�ɑ΂��ă\�[�g���s�������A�����N����Ȃ����Ƃ��m�F���܂��B
*			�v�f����1�̂܂܁A�擪�C�e���[�^�̎��������C�e���[�^�ƂȂ��Ă���ΐ����ł��B
*/
TYPED_TEST(QuicksortTest, OneItemExist)
{
	LinkedList<ScoreData> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�

	// �f�[�^��1���ǉ�����
	auto InsertItr = List.GetConstEnd();
	List.Insert(InsertItr, { 1, "Test1" });

	// �\�[�g�O�ɃT�C�Y�ƃC�e���[�^���`�F�b�N
	{
		auto Itr = List.GetConstBegin();
		++Itr;
		EXPECT_EQ(1, List.GetSize());
		EXPECT_TRUE(Itr == List.GetConstEnd());
	}

	// �\�[�g
	List.Quicksort(Comp);

	// �T�C�Y�ƃC�e���[�^���`�F�b�N
	{
		auto Itr = List.GetConstBegin();
		++Itr;
		EXPECT_EQ(1, List.GetSize());
		EXPECT_TRUE(Itr == List.GetConstEnd());
	}
}

/**
* @brief	2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
* @details	ID:2
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			�v�f��2�ȏ㎝���X�g�ɑ΂��ă\�[�g���s�������A�K�؂Ƀ\�[�g�o���Ă��邱�Ƃ��m�F���܂��B
*			�v�f���K�؂ɕ��ѕς����Ă���ΐ����ł��B
*/
TYPED_TEST(QuicksortTest, SomeItemExist)
{
	LinkedList<ScoreData> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�

	// �f�[�^��5���ǉ�����
	auto InsertItr = List.GetConstEnd();
	List.Insert(InsertItr, { 4, "Test4" });
	List.Insert(InsertItr, { 2, "Test2" });
	List.Insert(InsertItr, { 0, "Test0" });
	List.Insert(InsertItr, { 3, "Test3" });
	List.Insert(InsertItr, { 1, "Test1" });

	//*** �\�[�g
	List.Quicksort(Comp);

	//*** ���ѕς����o���Ă��邩�m�F
	// std::sort���g���ă\�[�g����
	std::vector<ScoreData> TestVector;
	TestVector.push_back({ 4, "Test4"});
	TestVector.push_back({ 2, "Test2"});
	TestVector.push_back({ 0, "Test0"});
	TestVector.push_back({ 3, "Test3"});
	TestVector.push_back({ 1, "Test1"});
	std::sort(TestVector.begin(), TestVector.end(), Comp);

	// std::sort�̌��ʂƔ�r����
	auto Begin     = List.GetConstBegin();
	auto End       = List.GetConstEnd();
	auto TestBegin = TestVector.begin();
	auto TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		EXPECT_EQ(TestBegin->Score, Data.Score);
		EXPECT_EQ(TestBegin->Name, Data.Name);
	}
}

/**
* @brief	�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
* @details	ID:3
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			���������N�C�b�N�\�[�g�����肵���\�[�g�o�Ȃ����Ƃ��m�F���܂��B
*			�v�f���\�[�g����ĕ��Ԃ��A����v�f�̏������ς���Ă���ΐ����ł��B
*/
TYPED_TEST(QuicksortTest, UnstableSort)
{
	LinkedList<ScoreData_US> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�

	// �f�[�^��5���ǉ�����
	auto InsertItr = List.GetConstEnd();
	List.Insert(InsertItr, ScoreData_US(4, "Test4", 5));
	List.Insert(InsertItr, ScoreData_US(2, "Test2", 3));
	List.Insert(InsertItr, ScoreData_US(0, "Test0", 1));
	List.Insert(InsertItr, ScoreData_US(3, "Test3", 4));
	List.Insert(InsertItr, ScoreData_US(0, "Test0", 0));
	List.Insert(InsertItr, ScoreData_US(1, "Test1", 2));

	//*** �\�[�g
	List.Quicksort(Comp);

	//*** ���ѕς����o���Ă��邩�m�F
	// qsort���g���ă\�[�g����
	std::vector<ScoreData_US> TestVector;
	TestVector.push_back(ScoreData_US(4, "Test4", 5));
	TestVector.push_back(ScoreData_US(2, "Test2", 3));
	TestVector.push_back(ScoreData_US(0, "Test0", 1));
	TestVector.push_back(ScoreData_US(3, "Test3", 4));
	TestVector.push_back(ScoreData_US(0, "Test0", 0));
	TestVector.push_back(ScoreData_US(1, "Test1", 2));
	qsort(TestVector.data(), TestVector.size(), sizeof(ScoreData_US), Comp.Comp);

	// qsort�̌��ʂƔ�r����
	auto Begin     = List.GetConstBegin();
	auto End       = List.GetConstEnd();
	auto TestBegin = TestVector.begin();
	auto TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		EXPECT_EQ(TestBegin->Score, Data.Score);
		EXPECT_EQ(TestBegin->Name, Data.Name);
		EXPECT_EQ(TestBegin->Element, Data.Element);
	}
}

/**
* @brief	����ς݃��X�g�Ƀ\�[�g�����s�������̋���
* @details	ID:4
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			���Ƀ\�[�g����Ă��郊�X�g�ɑ΂��Ă�����x�\�[�g�������ɁA�v�f�̕��т��ς���Ă��Ȃ����Ƃ��m�F���܂��B
*			1��ڂ̃\�[�g�̌��ʂ�2��ڂ̃\�[�g�̌��ʂ��ς��Ȃ���ΐ����ł��B
*/
TYPED_TEST(QuicksortTest, SortSecond)
{
	LinkedList<ScoreData> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�

	// �f�[�^��5���ǉ�����
	auto InsertItr = List.GetConstEnd();
	List.Insert(InsertItr, { 4, "Test4" });
	List.Insert(InsertItr, { 2, "Test2" });
	List.Insert(InsertItr, { 0, "Test0" });
	List.Insert(InsertItr, { 3, "Test3" });
	List.Insert(InsertItr, { 1, "Test1" });

	//*** �\�[�g
	List.Quicksort(Comp);

	//*** ���ѕς����o���Ă��邩�m�F
	// std::sort���g���ă\�[�g����
	std::vector<ScoreData> TestVector;
	TestVector.push_back({ 4, "Test4" });
	TestVector.push_back({ 2, "Test2" });
	TestVector.push_back({ 0, "Test0" });
	TestVector.push_back({ 3, "Test3" });
	TestVector.push_back({ 1, "Test1" });
	std::sort(TestVector.begin(), TestVector.end(), Comp);

	// std::sort�̌��ʂƔ�r����
	auto Begin     = List.GetConstBegin();
	auto End       = List.GetConstEnd();
	auto TestBegin = TestVector.begin();
	auto TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		ASSERT_EQ(TestBegin->Score, Data.Score);
		ASSERT_EQ(TestBegin->Name, Data.Name);
	}

	// ������x�\�[�g���Ċm�F����
	List.Quicksort(Comp);
	Begin     = List.GetConstBegin();
	End       = List.GetConstEnd();
	TestBegin = TestVector.begin();
	TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		EXPECT_EQ(TestBegin->Score, Data.Score);
		EXPECT_EQ(TestBegin->Name, Data.Name);
	}
}

/**
* @brief	��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
* @details	ID:5
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			�\�[�g�����s�������X�g�ɑ΂��āA�v�f��}�����A�Ăу\�[�g�������̋������m�F���܂��B
*			�v�f���K�؂ɕ��ѕς����Ă���ΐ����ł��B
*/
TYPED_TEST(QuicksortTest, SortInsert)
{
	LinkedList<ScoreData> List;		// ���X�g
	TypeParam Comp;					// ��r�֐�

	// �f�[�^��5���ǉ�����
	{
		auto InsertItr = List.GetConstEnd();
		List.Insert(InsertItr, { 4, "Test4" });
		List.Insert(InsertItr, { 2, "Test2" });
		List.Insert(InsertItr, { 0, "Test0" });
		List.Insert(InsertItr, { 3, "Test3" });
		List.Insert(InsertItr, { 1, "Test1" });
	}

	//*** �\�[�g
	List.Quicksort(Comp);

	//*** ���ѕς����o���Ă��邩�m�F
	// std::sort���g���ă\�[�g����
	std::vector<ScoreData> TestVector;
	TestVector.push_back({ 4, "Test4" });
	TestVector.push_back({ 2, "Test2" });
	TestVector.push_back({ 0, "Test0" });
	TestVector.push_back({ 3, "Test3" });
	TestVector.push_back({ 1, "Test1" });
	std::sort(TestVector.begin(), TestVector.end(), Comp);

	// std::sort�̌��ʂƔ�r����
	auto Begin     = List.GetConstBegin();
	auto End       = List.GetConstEnd();
	auto TestBegin = TestVector.begin();
	auto TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		ASSERT_EQ(TestBegin->Score, Data.Score);
		ASSERT_EQ(TestBegin->Name, Data.Name);
	}

	// �擪�A�����A�擪�̎��Ƀf�[�^��ǉ�����
	{
		auto InsertItr = List.GetConstBegin();
		List.Insert(InsertItr, { 20, "Test20" });
		
		++InsertItr;
		List.Insert(InsertItr, { 10, "Test10" });

		InsertItr = List.GetConstEnd();
		List.Insert(InsertItr, { 30, "Test30" });
	}

	// �����悤�Ƀe�X�g�p��Vector�ɑ}��
	{
		auto InsertItr = TestVector.cbegin();
		TestVector.insert(InsertItr, { 20, "Test20" });

		InsertItr = TestVector.cbegin();
		++InsertItr;
		TestVector.insert(InsertItr, { 10, "Test10" });

		InsertItr = TestVector.cend();
		TestVector.insert(InsertItr, { 30, "Test30" });
	}

	// ������x�\�[�g���Ċm�F����
	List.Quicksort(Comp);
	std::sort(TestVector.begin(), TestVector.end(), Comp);

	Begin     = List.GetConstBegin();
	End       = List.GetConstEnd();
	TestBegin = TestVector.begin();
	TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		EXPECT_EQ(TestBegin->Score, Data.Score);
		EXPECT_EQ(TestBegin->Name, Data.Name);
	}
}

/**
* @brief	�L�[�w������Ȃ�����(nullptr��n����)���̋���
* @details	ID:6
*			�N�C�b�N�\�[�g�̃e�X�g�ł��B
*			�L�[�̎w������Ȃ������ꍇ�Ƀ\�[�g�����s�������̋������m�F���܂��B
*			�v�f�����ѕς����Ă��Ȃ���ΐ����ł��B
*/
TEST(Quicksort, NoKeySelected)
{
	LinkedList<ScoreData> List;		// ���X�g
	
	// �f�[�^��5���ǉ�����
	auto InsertItr = List.GetConstEnd();
	List.Insert(InsertItr, { 4, "Test4" });
	List.Insert(InsertItr, { 2, "Test2" });
	List.Insert(InsertItr, { 0, "Test0" });
	List.Insert(InsertItr, { 3, "Test3" });
	List.Insert(InsertItr, { 1, "Test1" });

	//*** �\�[�g
	List.Quicksort(
		[](const ScoreData&, const ScoreData&) 
		{
			return false; 
		});

	//*** ���ѕς����o���Ă��邩�m�F
	// std::sort���g���ă\�[�g����
	std::vector<ScoreData> TestVector;
	TestVector.push_back({ 4, "Test4" });
	TestVector.push_back({ 2, "Test2" });
	TestVector.push_back({ 0, "Test0" });
	TestVector.push_back({ 3, "Test3" });
	TestVector.push_back({ 1, "Test1" });

	// �ς���ĂȂ����Ƃ��m�F����
	auto Begin     = List.GetConstBegin();
	auto End       = List.GetConstEnd();
	auto TestBegin = TestVector.begin();
	auto TestEnd   = TestVector.end();
	for (; Begin != End && TestBegin != TestEnd; ++Begin, ++TestBegin)
	{
		auto& Data = *Begin;
		EXPECT_EQ(TestBegin->Score, Data.Score);
		EXPECT_EQ(TestBegin->Name, Data.Name);
	}
}

#pragma endregion
#pragma region ***** �C�e���[�^�Ԃ̋����𑪂� ******

/**
* @brief	�v�f����0�̎��A�擪�C�e���[�^�Ɩ����C�e���[�^��n�����Ƃ��̋���
* @details	ID:9
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�v�f����0�̎��ADistance�ɐ擪�C�e���[�^�Ɩ����C�e���[�^��n�������̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidIterator)���Ԃ�ΐ����ł��B
*/
TEST(Distance, NoItem)
{
	// ���X�g
	LinkedList<ScoreData> List;

	// ��R���X�g�ȃC�e���[�^
	auto Dis = List.Distance(List.GetBegin(), List.GetEnd());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);

	// �R���X�g�ȃC�e���[�^
	Dis = List.Distance(List.GetConstBegin(), List.GetConstEnd());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);
}

/**
* @brief	�v�f����0�̎��A�擪�C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�����Ƃ��̋���
* @details	ID:10
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�v�f����0�̎��ADistance�ɐ擪�C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�������̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidIterator)���Ԃ�ΐ����ł��B
*/
TEST(Distance, NoItemRev)
{
	// ���X�g
	LinkedList<ScoreData> List;

	// ��R���X�g�ȃC�e���[�^
	auto Dis = List.Distance(List.GetEnd(), List.GetBegin());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);

	// �R���X�g�ȃC�e���[�^
	Dis = List.Distance(List.GetConstEnd(), List.GetConstBegin());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);
}

/**
* @brief	�����̗v�f�������A�擪�C�e���[�^�Ɩ����C�e���[�^��n�����Ƃ��̋���
* @details	ID:11
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�C�e���[�^�Ɩ����C�e���[�^��n�������̋������m�F���܂��B
*			�v�f���Ɠ����l���Ԃ�ΐ����ł��B
*/
TEST_F(DistanceF, SomeItem)
{
	// ��R���X�g�ȃC�e���[�^
	auto Dis = pList->Distance(pList->GetBegin(), pList->GetEnd());
	EXPECT_EQ(pList->GetSize(), Dis);		// �v�f���Ɠ����ł��邱�Ƃ̊m�F

	// �R���X�g�ȃC�e���[�^
	Dis = pList->Distance(pList->GetConstBegin(), pList->GetConstEnd());
	EXPECT_EQ(pList->GetSize(), Dis);		// �v�f���Ɠ����ł��邱�Ƃ̊m�F
}

/**
* @brief	�����̗v�f�������A�擪�C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�����Ƃ��̋���
* @details	ID:12
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�������̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidIterator)���Ԃ�ΐ����ł��B
*/
TEST_F(DistanceF, SomeItemRev)
{
	// ��R���X�g�ȃC�e���[�^
	auto Dis = pList->Distance(pList->GetEnd(), pList->GetBegin());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);

	// �R���X�g�ȃC�e���[�^
	Dis = pList->Distance(pList->GetConstEnd(), pList->GetConstBegin());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);
}

/**
* @brief	�����̗v�f�������A�擪�C�e���[�^�Ɛ擪�ł������ł��Ȃ��C�e���[�^��n�����Ƃ��̋���
* @details	ID:13
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�C�e���[�^�Ɛ擪�ł������ł��Ȃ���n�������̋������m�F���܂��B
*			�擪����Y���C�e���[�^�܂ŃC���N�������g�����A���ꂪ�߂�l�Ɠ����ł���ΐ����ł��B
*/
TEST_F(DistanceF, BeginToCenter)
{
	// ��R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetBegin();
		++Itr;
		auto Dis = pList->Distance(pList->GetBegin(), Itr);
		EXPECT_EQ(1, Dis);		// 1��C���N�������g���Ă���̂�
	}

	// �R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetConstBegin();
		++Itr;
		auto Dis = pList->Distance(pList->GetConstBegin(), Itr);
		EXPECT_EQ(1, Dis);		// 1��C���N�������g���Ă���̂�
	}
}

/**
* @brief	�����̗v�f�������A�擪�C�e���[�^�Ɛ擪�ł������ł��Ȃ��C�e���[�^���t�ɂ��ēn�����Ƃ��̋���
* @details	ID:14
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�C�e���[�^�Ɛ擪�ł������ł��Ȃ����t�ɂ��ēn�������̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kUnreachable)���Ԃ�ΐ����ł��B
*/
TEST_F(DistanceF, BeginToCenterRev)
{
	// ��R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetBegin();
		++Itr;
		auto Dis = pList->Distance(Itr, pList->GetBegin());
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kUnreachable, Dis);
	}

	// �R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetConstBegin();
		++Itr;
		auto Dis = pList->Distance(Itr, pList->GetConstBegin());
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kUnreachable, Dis);
	}
}

/**
* @brief	�����̗v�f�������A�擪�ł������ł��Ȃ��C�e���[�^�Ɩ����C�e���[�^��n�����Ƃ��̋���
* @details	ID:15
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�ł������ł��Ȃ��C�e���[�^�Ɩ����C�e���[�^��n�������̋������m�F���܂��B
*			��������Y���C�e���[�^�܂Ńf�N�������g�����A���ꂪ�߂�l�Ɠ����ł���ΐ����ł��B
*/
TEST_F(DistanceF, CenterToEnd)
{
	// ��R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetEnd();
		--Itr;
		auto Dis = pList->Distance(Itr, pList->GetEnd());
		EXPECT_EQ(1, Dis);		// 1��f�N�������g���Ă���̂�
	}

	// �R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetConstEnd();
		--Itr;
		auto Dis = pList->Distance(Itr, pList->GetConstEnd());
		EXPECT_EQ(1, Dis);		// 1��f�N�������g���Ă���̂�
	}
}

/**
* @brief	�����̗v�f�������A�擪�ł������ł��Ȃ��C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�����Ƃ��̋���
* @details	ID:16
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			�����̗v�f�������ADistance�ɐ擪�ł������ł��Ȃ��C�e���[�^�Ɩ����C�e���[�^���t�ɂ��ēn�������̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidIterator)���Ԃ�ΐ����ł��B
*/
TEST_F(DistanceF, CenterToEndRev)
{
	// ��R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetEnd();
		--Itr;
		auto Dis = pList->Distance(pList->GetEnd(), Itr);
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);
	}

	// �R���X�g�ȃC�e���[�^
	{
		auto Itr = pList->GetConstEnd();
		--Itr;
		auto Dis = pList->Distance(pList->GetConstEnd(), Itr);
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kInvalidIterator, Dis);
	}
}

/**
* @brief	Distance�ɕʂ̃��X�g�̃C�e���[�^��n�����Ƃ��̋���
* @details	ID:17
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			Distance�ɕʂ̃��X�g�̃C�e���[�^��n�����Ƃ��̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidReference)���Ԃ�ΐ����ł��B
*/
TEST(Distance, DifferentListItr)
{
	LinkedList<ScoreData> List1;
	LinkedList<ScoreData> List2;

	auto Dis = List1.Distance(List2.GetBegin(), List2.GetEnd());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidReference, Dis);

	Dis = List1.Distance(List2.GetConstBegin(), List2.GetConstEnd());
	EXPECT_LT(Dis, 0);
	EXPECT_EQ(LinkedListError::kInvalidReference, Dis);
}

/**
* @brief	Distance�ɕs���ȃC�e���[�^��n�����Ƃ��̋���
* @details	ID:18
*			�C�e���[�^�ǂ����̋����𑪂�@�\�̃`�F�b�N�ł��B
*			Distance�ɕʂ̃��X�g�̃C�e���[�^��n�����Ƃ��̋������m�F���܂��B
*			�G���[�l : 0����(LinkedListError::kInvalidReference)���Ԃ�ΐ����ł��B
*/
TEST(Distance, InvalidItr)
{
	LinkedList<ScoreData> List;

	// ��R���X�g�ȃC�e���[�^
	{
		LinkedList<ScoreData>::Iterator InvalidItr1;
		LinkedList<ScoreData>::Iterator InvalidItr2;

		auto Dis = List.Distance(InvalidItr1, InvalidItr2);
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kInvalidReference, Dis);
	}

	// �R���X�g�ȃC�e���[�^
	{
		LinkedList<ScoreData>::ConstIterator ConstInvalidItr1;
		LinkedList<ScoreData>::ConstIterator ConstInvalidItr2;

		auto Dis = List.Distance(ConstInvalidItr1, ConstInvalidItr2);
		EXPECT_LT(Dis, 0);
		EXPECT_EQ(LinkedListError::kInvalidReference, Dis);
	}
}

#pragma endregion

}	// ex03_Quicksort
