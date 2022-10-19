/**
* @brief	�o�������X�g�̃e�X�g
* @date		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../StackQueue/LinkedList.h"
#include "ScoreData.h"
#include "TestHelper.h"

/**
* @namespace	ex01_LinkedList
* @brief		�o�������X�g�̃e�X�g
*/
namespace ex01_LinkedList
{

//===== �^�G�C���A�X =====

using InserDataF             = LinkedListTestFixture;
using DeleteDataF            = LinkedListTestFixture;
using GetBeginIteratorF      = LinkedListTestFixture;
using GetBeginConstIteratorF = LinkedListTestFixture;
using GetEndIteratorF        = LinkedListTestFixture;
using GetEndConstIteratorF   = LinkedListTestFixture;

#pragma region ***** �f�[�^���̎擾 *****
/**
* @brief	���X�g����ł���ꍇ�̖߂�l
* @details	ID:0
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g����̏ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenEmpty)
{
	LinkedList<ScoreData> List;
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	���X�g�����ւ̑}�����s�����ۂ̖߂�l
* @details	ID:1
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�����ɑ}�����s�������Ƃ̏ꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenInsertEnd)
{
	LinkedList<ScoreData> List;
	ScoreData Data{ 0, "Test0" };

	auto Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));
	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	���X�g�����ւ̑}�������s�����ۂ̖߂�l
* @details	ID:2
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�����ɑ}�����s���A�}�������s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenInsertEndFailed)
{
	//*** �}���Ɏ��s����̂̓������m�ۂɎ��s�������Ȃ̂ŃX�L�b�v
	
	//LinkedList<ScoreData> List;
	//ScoreData Data{-1, ""};

	//auto Itr = List.GetEnd();
	//ASSERT_FALSE(List.Insert(Itr, Data));
	//EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	�f�[�^�̑}�����s�����ۂ̖߂�l
* @details	ID:3
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�ɑ}�����s�������Əꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenInsert)
{
	LinkedList<ScoreData> List;
	ScoreData Data{ 3, "Test3" };

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
* @details	ID:4
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�ɑ}�����s���A�}�������s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenInsertFailed)
{
	//*** �}���Ɏ��s����̂̓������m�ۂɎ��s�������Ȃ̂ŃX�L�b�v

	//LinkedList<ScoreData> List;
	//ScoreData Data{-1, ""};

	//auto Itr = List.GetBegin();
	//ASSERT_FALSE(List.Insert(Itr, Data));
	//EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:5
*			�f�[�^�����擾�̃e�X�g�ł��B
*			�f�[�^�̍폜���s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDelete)
{
	LinkedList<ScoreData> List;
	ScoreData Data{ 5, "Test5" };

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Itr = List.GetBegin();	// �擾���Ȃ���
	ASSERT_TRUE(List.Delete(Itr));
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:6
*			�f�[�^�����擾�̃e�X�g�ł��B
*			�f�[�^�̍폜���s���A�폜�Ɏ��s�����ꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDeleteFailed)
{
	LinkedList<ScoreData> List;
	ScoreData Data{ 6, "Test6" };

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	LinkedList<ScoreData>::ConstIterator InvalidItr;	// �����ȃC�e���[�^
	ASSERT_FALSE(List.Delete(InvalidItr));

	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:7
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g����̏�ԂŃf�[�^�̍폜���s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDeleteEmptyList)
{
	LinkedList<ScoreData> List;

	auto Itr = List.GetEnd();	// �C�e���[�^
	ASSERT_FALSE(List.Delete(Itr));

	EXPECT_EQ(List.GetSize(), 0);
}
#pragma endregion

#pragma region ***** �f�[�^�̑}�� *****
/**
* @brief	���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
* @details	ID:9
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g����̏�ԂŐ擪�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST(InsertData, WhenEmptyTo)
{
	LinkedList<ScoreData> List;
	ScoreData Data{ 9, "Test9" };

	// �擪�C�e���[�^
	{
		auto Itr = List.GetBegin();
		EXPECT_TRUE(List.Insert(Itr, Data));
	}

	// �����C�e���[�^
	{
		auto ConstItr = List.GetEnd();
		EXPECT_TRUE(List.Insert(ConstItr, Data));
	}
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
* @details	ID:10
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�擪�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(InserDataF, WhenSomeDataExistToBegin)
{
	//*** �擪�̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetBegin();
	ScoreData Data{ 10, "Test10" };
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** �ȑO�̐擪�v�f��2�Ԗڂɂ��邱�Ƃ��m�F����
	Itr = pList->GetBegin();
	++Itr;
	auto& TestData = *Itr;
	EXPECT_EQ(0, TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�����R���X�g�C�e���[�^�̎擾��n���āA�}�������ۂ̋���
* @details	ID:11
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�����Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(InserDataF, WhenSomeDataExistToEnd)
{
	//*** �����̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetEnd();
	ScoreData Data{ 11, "Test11" };
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** ������1�O�ɒǉ�����Ă��邩�m�F����
	Itr = pList->GetEnd();
	--Itr;
	auto& TestData = *Itr;
	EXPECT_EQ(11, TestData.Score);
	EXPECT_EQ("Test11", TestData.Name);
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
* @details	ID:12
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�擪�ł������ł��Ȃ��ꏊ�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			�߂�l��True�ŁA���̃f�[�^�ɉe�����Ȃ���ΐ����ł��B
*/
TEST_F(InserDataF, WhenSomeDataExistToCenter)
{
	//*** �擪�̎��̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetBegin();
	{
		ScoreData Data{ 12, "Test12" };
		++Itr;
		EXPECT_TRUE(pList->Insert(Itr, Data));
	}

	//*** �擪����2�i�񂾈ʒu�Ɍ��̃f�[�^�������OK
	{
		Itr = pList->GetBegin();
		++Itr;
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(1, Data.Score);
		EXPECT_EQ("Test1", Data.Name);
	}

	//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
	// �O���珇�Ԃ�
	// Score == 0;
	// Name == "Test0";
	// Score == 12;
	// Name == "Test12";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// �Ȃ�OK

	ScoreData TestData[4] = {
		{ 0, "Test0" },
		{ 12, "Test12" },
		{ 1, "Test1" },
		{ 2, "Test2" }
	};

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIterator���w�肵�đ}�����s�����ۂ̋���
* @details	ID:13
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�R���X�g�ȃC�e���[�^�𗘗p���Đ擪, ����, �擪�ł������ł��Ȃ��v�f�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(InserDataF, InsertWithConstIteratorToBegin)
{
	{
		//*** �擪�������R���X�g�ȃC�e���[�^���g���ăf�[�^��}������B
		auto ConstItr = pList->GetConstBegin();
		ScoreData InsertData{ 13, "Test13" };
		EXPECT_TRUE(pList->Insert(ConstItr, InsertData));

		//*** ���Ƃ��Ɛ擪�ɂ������f�[�^��2�Ԗڂɗ��Ă��邩�`�F�b�N
		auto Itr = pList->GetBegin();
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(0, Data.Score);
		EXPECT_EQ("Test0", Data.Name);

		//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
		// �O���珇�Ԃ�
		// Score == 13;
		// Name == "Test13";
		// Score == 0;
		// Name == "Test0";
		// Score == 1;
		// Name == "Test1";
		// Score == 2;
		// Name == "Test2";
		// �Ȃ�OK

		ScoreData TestData[4] = {
			{ 13, "Test13" },
			{ 0,  "Test0" },
			{ 1,  "Test1" },
			{ 2,  "Test2" }
		};

		TestListItem(*pList, TestData, _countof(TestData));
	}

	{
		//*** �������w���R���X�g�ȃC�e���[�^���g���ăf�[�^��}������
		auto ConstItr = pList->GetConstEnd();
		ScoreData InsertData{ 14, "Test13_End" };
		EXPECT_TRUE(pList->Insert(ConstItr, InsertData));

		//*** ���҂����ʒu�ɓ����Ă��邩�`�F�b�N
		auto Itr = pList->GetEnd();
		--Itr;
		auto& Data = *Itr;
		EXPECT_EQ(14, Data.Score);
		EXPECT_EQ("Test13_End", Data.Name);

		//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
		// �O���珇�Ԃ�
		// Score == 13;
		// Name == "Test13";
		// Score == 0;
		// Name == "Test0";
		// Score == 1;
		// Name == "Test1";
		// Score == 2;
		// Name == "Test2";
		// Score == 14
		// Name == "Test13_End"
		// �Ȃ�OK

		ScoreData TestData[5] = {
			{ 13, "Test13" },
			{ 0,  "Test0" },
			{ 1,  "Test1" },
			{ 2,  "Test2" },
			{ 14, "Test13_End" }
		};

		TestListItem(*pList, TestData, _countof(TestData));
	}

	{
		//*** �擪�̎��������R���X�g�ȃC�e���[�^���g���ăf�[�^��}������B
		auto ConstItr = pList->GetConstBegin();
		ScoreData InsertData{ 15, "Test13_Center" };
		++ConstItr;
		EXPECT_TRUE(pList->Insert(ConstItr, InsertData));

		//*** �擪��2���ɂ���Ă��邩�`�F�b�N
		auto Itr = pList->GetBegin();
		++Itr;
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(0, Data.Score);
		EXPECT_EQ("Test0", Data.Name);

		//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
		// �O���珇�Ԃ�
		// Score == 13;
		// Name == "Test13";
		// Score == 15;
		// Name == "Test13_Center";
		// Score == 0;
		// Name == "Test0";
		// Score == 1;
		// Name == "Test1";
		// Score == 2;
		// Name == "Test2";
		// Score == 14;
		// Name == "Test13_End";
		// �Ȃ�OK

		ScoreData TestData[6] = {
			{ 13, "Test13" },
			{ 15, "Test13_Center" },
			{ 0,  "Test0" },
			{ 1,  "Test1" },
			{ 2,  "Test2" },
			{ 14, "Test13_End" },
		};

		TestListItem(*pList, TestData, _countof(TestData));
	}
}

/**
* @brief	�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
* @details	ID:14
*			�f�[�^�̑}���̃e�X�g�ł��B
*			�s���ȃC�e���[�^���g�p���đ}���������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST(InsertData, WithInvalidIterator)
{
	LinkedList<ScoreData> List1;
	ScoreData Data{ 14, "Test14" };

	// �����Q�Ƃ��Ă��Ȃ��C�e���[�^�ő}��
	LinkedList<ScoreData>::Iterator InvalidItr;
	EXPECT_FALSE(List1.Insert(InvalidItr, Data));

	// �ʂ̃��X�g���Q�Ƃ��Ă���C�e���[�^�ő}��
	LinkedList<ScoreData> List2;
	auto InvalidRefItr = List2.GetBegin();
	EXPECT_FALSE(List1.Insert(InvalidRefItr, Data));
}
#pragma endregion

#pragma region ***** �f�[�^�̍폜 *****
/**
* @brief	���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
* @details	ID:16
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�C�e���[�^�A�����C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST(DeleteData, WithEmptyListBegin)
{
	LinkedList<ScoreData> List;

	// �擪�C�e���[�^
	{
		// �擪�C�e���[�^�擾
		auto Itr = List.GetBegin();

		// �����`�F�b�N
		EXPECT_FALSE(List.Delete(Itr));
	}

	// �����C�e���[�^
	{
		// �����C�e���[�^�擾
		auto Itr = List.GetEnd();

		// �����`�F�b�N
		EXPECT_FALSE(List.Delete(Itr));
	}
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
* @details	ID:17
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�擪�C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(DeleteDataF, WithBegin)
{
	// �擪�C�e���[�^���w�肵�č폜
	auto Itr = pList->GetBegin();
	EXPECT_TRUE(pList->Delete(Itr));
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
* @details	ID:18
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�����C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST_F(DeleteDataF, WithEnd)
{
	// �����C�e���[�^���w�肵�č폜
	auto Itr = pList->GetEnd();
	EXPECT_FALSE(pList->Delete(Itr));
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
* @details	ID:19
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�擪�ł������ł��Ȃ��C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(DeleteDataF, Anywhere)
{
	// �擪�C�e���[�^�̎��̃C�e���[�^���w�肵�č폜
	auto Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// ���҂����ʒu�ɔz�u����Ă��邩�A���̗v�f�ɉe�����Ȃ����`�F�b�N
	ScoreData TestData[2] = {
		{ 0, "Test0"},
		{ 2, "Test2" }
	};

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIterator���w�肵�č폜���s�����ۂ̋���
* @details	ID:20
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(DeleteDataF, AnywhereWithConstIterator)
{
	// �擪�C�e���[�^�̎��̃C�e���[�^���w�肵�č폜
	auto Itr = pList->GetConstBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// ���҂����ʒu�ɔz�u����Ă��邩�A���̗v�f�ɉe�����Ȃ����`�F�b�N
	ScoreData TestData[2] = {
		{ 0, "Test0"},
		{ 2, "Test2" }
	};

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
* @details	ID:21
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�s���ȃC�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(DeleteDataF, InvalidIterator)
{
	// �s���ȃC�e���[�^���w�肵�č폜����
	LinkedList<ScoreData>::Iterator Itr;
	EXPECT_FALSE(pList->Delete(Itr));
}

#pragma endregion

#pragma region ***** �擪�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:23
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*			�_�~�[�m�[�h���w���C�e���[�^����ăf�[�^�ɃA�N�Z�X�����
*			Assert���������Astderr�� Reference To DummyNode ���܂ޕ�����
*			�o�͂����̂ŁAEXPECT_DEATH()�𗘗p���ăe�X�g���܂��B
*/
TEST(GetBeginIterator, WhenEmpty)
{
#if _DEBUG
	LinkedList<ScoreData> List;

	// �擪�C�e���[�^�擾
	auto Itr = List.GetBegin();

	// �����`�F�b�N
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:24
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, When1ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��1���ǉ�
	ScoreData Data{ 24, "Test24" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = List.GetBegin();

	// �����`�F�b�N
	auto& TestData = *BeginItr;
	EXPECT_EQ(24, TestData.Score);
	EXPECT_EQ("Test24", TestData.Name);
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:25
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, When2ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��2���ǉ�
	ScoreData Data{ 1, "Test1" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Data = { 0, "Test0" };
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = List.GetBegin();

	// �����`�F�b�N
	auto& TestData = *BeginItr;
	EXPECT_EQ(0, TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:26
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			�擪, ����, �擪�ł������ł��Ȃ��ʒu�ɑ}��������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, WhenInsertBegin)
{
	// ���X�g
	LinkedList<ScoreData> List;

	//*** �擪�Ƀf�[�^��}������
	{
		ScoreData Data{ 26, "Test26_Begin" };
		auto Itr = List.GetBegin();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �擪�C�e���[�^���擾
		auto BeginItr = List.GetBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}

	//*** �����Ƀf�[�^��ǉ�����
	{
		ScoreData Data = { 27, "Test26_End" };
		auto Itr = List.GetEnd();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �擪�C�e���[�^���Ď擾
		auto BeginItr = List.GetBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}

	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	{
		ScoreData Data = { 28, "Test26_Center" };
		auto Itr = List.GetBegin();
		++Itr;
		ASSERT_TRUE(List.Insert(Itr, Data));
		
		// �擪�C�e���[�^���Ď擾
		auto BeginItr = List.GetBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:27
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f, �����v�f, �擪�ł������ł��Ȃ��v�f���폜������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(GetBeginIteratorF, WhenDelete)
{
	// ����(�擪�ł������ł��Ȃ�)�v�f���폜
	// �擪�v�f���폜
	// �����v�f���폜
	// �̏��Ŋm�F����B
	// �Ȃ̂ŁA�f�[�^��4�ȏ�K�v�ɂȂ邽�߂���1�ǉ�����B
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	//*** �擪�ł������ł��Ȃ��v�f���폜���āA�擪�v�f���m�F����
	{
		// �擪�C�e���[�^���擾���āA�擪�ł������ł��Ȃ��v�f�ɐi�߂�
		auto CenterItr = pList->GetBegin();
		++CenterItr;

		// �폜
		pList->Delete(CenterItr);

		// �����`�F�b�N
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(0, TestData.Score);
		EXPECT_EQ("Test0", TestData.Name);
	}

	//*** �擪�v�f���폜���āA�擪�v�f���m�F����
	{
		// �擪�v�f���폜
		auto BeginItr = pList->GetBegin();
		pList->Delete(BeginItr);

		// �����`�F�b�N
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}

	//*** �����v�f���폜���āA�擪�v�f���m�F����
	{
		// �����v�f���폜
		auto EndItr = pList->GetEnd();
		--EndItr;
		pList->Delete(EndItr);

		// �����`�F�b�N
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** �擪�R���X�g�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:29
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*			�_�~�[�m�[�h���w���C�e���[�^����ăf�[�^�ɃA�N�Z�X�����
*			Assert���������Astderr�� Reference To DummyNode ���܂ޕ�����
*			�o�͂����̂ŁAEXPECT_DEATH()�𗘗p���ăe�X�g���܂��B
*/
TEST(GetBeginConstIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList<ScoreData> List;

	// �擪�R���X�g�C�e���[�^�擾
	auto Itr = List.GetConstBegin();

	// �����`�F�b�N
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:30
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, When1ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��1���ǉ�
	ScoreData Data{ 30, "Test30" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = List.GetConstBegin();

	// �����`�F�b�N
	auto& TestData = *BeginItr;
	EXPECT_EQ(30, TestData.Score);
	EXPECT_EQ("Test30", TestData.Name);
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:31
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, When2ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��2���ǉ�
	ScoreData Data{ 1, "Test1" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Data = { 0, "Test0" };
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = List.GetConstBegin();

	// �����`�F�b�N
	auto& TestData = *BeginItr;
	EXPECT_EQ(0, TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:32
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			�擪, ����, �擪�ł������ł��Ȃ��ʒu�ɑ}��������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, WhenInsertBegin)
{
	// ���X�g
	LinkedList<ScoreData> List;

	//*** �擪�Ƀf�[�^��}������
	{
		ScoreData Data{ 32, "Test32_Begin" };
		auto Itr = List.GetBegin();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �擪�C�e���[�^���擾
		auto BeginItr = List.GetConstBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}

	//*** �����Ƀf�[�^��ǉ�����
	{
		ScoreData Data = { 33, "Test33_End" };
		auto Itr = List.GetEnd();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �擪�C�e���[�^���Ď擾
		auto BeginItr = List.GetConstBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}

	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	{
		ScoreData Data = { 34, "Test34_Center" };
		auto Itr = List.GetBegin();
		++Itr;
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �擪�C�e���[�^���Ď擾
		auto BeginItr = List.GetConstBegin();

		// �����`�F�b�N
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:33
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f, �����v�f, �擪�ł������ł��Ȃ��v�f���폜������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(GetBeginConstIteratorF, WhenDelete)
{
	// ����(�擪�ł������ł��Ȃ�)�v�f���폜
	// �擪�v�f���폜
	// �����v�f���폜
	// �̏��Ŋm�F����B
	// �Ȃ̂ŁA�f�[�^��4�ȏ�K�v�ɂȂ邽�߂���1�ǉ�����B
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	//*** �擪�ł������ł��Ȃ��v�f���폜���āA�擪�v�f���m�F����
	{
		// �擪�C�e���[�^���擾���āA�擪�ł������ł��Ȃ��v�f�ɐi�߂�
		auto CenterItr = pList->GetBegin();
		++CenterItr;

		// �폜
		pList->Delete(CenterItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(0, TestData.Score);
		EXPECT_EQ("Test0", TestData.Name);
	}

	//*** �擪�v�f���폜���āA�擪�v�f���m�F����
	{
		// �擪�v�f���폜
		auto BeginItr = pList->GetBegin();
		pList->Delete(BeginItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}

	//*** �����v�f���폜���āA�擪�v�f���m�F����
	{
		// �����v�f���폜
		auto EndItr = pList->GetEnd();
		--EndItr;
		pList->Delete(EndItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** �����C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:35
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*			�_�~�[�m�[�h���w���C�e���[�^����ăf�[�^�ɃA�N�Z�X�����
*			Assert���������Astderr�� Reference To DummyNode ���܂ޕ�����
*			�o�͂����̂ŁAEXPECT_DEATH()�𗘗p���ăe�X�g���܂��B
*/
TEST(GetEndIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList<ScoreData> List;

	// �����C�e���[�^�擾
	auto Itr = List.GetEnd();

	// �����`�F�b�N
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:36
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, When1ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��1���ǉ�
	ScoreData Data{ 36, "Test36" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = List.GetEnd();
	--EndItr;

	// �����`�F�b�N
	auto& TestData = *EndItr;
	EXPECT_EQ(36, TestData.Score);
	EXPECT_EQ("Test36", TestData.Name);
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:37
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, When2ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��2���ǉ�
	ScoreData Data{ 1, "Test1" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Data = { 0, "Test0" };
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = List.GetEnd();
	--EndItr;

	// �����`�F�b�N
	auto& TestData = *EndItr;
	EXPECT_EQ(1, TestData.Score);
	EXPECT_EQ("Test1", TestData.Name);
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:38
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			�擪, ����, �擪�ł������ł��Ȃ��ʒu�ɑ}��������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, WhenInsertBegin)
{
	// ���X�g
	LinkedList<ScoreData> List;

	//*** �擪�Ƀf�[�^��}������
	{
		ScoreData Data{ 38, "Test38_Begin" };
		auto Itr = List.GetBegin();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���擾
		auto EndItr = List.GetEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

			// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(38, TestData.Score);
		EXPECT_EQ("Test38_Begin", TestData.Name);
	}

	// �����Ƀf�[�^��ǉ�����
	{
		ScoreData Data = { 39, "Test38_End" };
		auto Itr = List.GetEnd();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���Ď擾
		auto EndItr = List.GetEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

			// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(39, TestData.Score);
		EXPECT_EQ("Test38_End", TestData.Name);
	}

	//*** �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	{
		ScoreData Data = { 40, "Test38_Center" };
		auto Itr = List.GetBegin();
		++Itr;
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���Ď擾
		auto EndItr = List.GetEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

		// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(39, TestData.Score);
		EXPECT_EQ("Test38_End", TestData.Name);
	}
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:39
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f, �����v�f, �擪�ł������ł��Ȃ��v�f���폜������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(GetEndIteratorF, WhenDelete)
{
	// ����(�擪�ł������ł��Ȃ�)�v�f���폜
	// �擪�v�f���폜
	// �����v�f���폜
	// �̏��Ŋm�F����B
	// �Ȃ̂ŁA�f�[�^��4�ȏ�K�v�ɂȂ邽�߂���1�ǉ�����B
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	//*** �擪�ł������ł��Ȃ��v�f���폜���āA�����v�f���m�F����
	{
		// �擪�C�e���[�^���擾���āA�擪�ł������ł��Ȃ��v�f�ɐi�߂�
		auto CenterItr = pList->GetBegin();
		++CenterItr;

		// �擪�ł������ł��Ȃ��v�f���폜����
		pList->Delete(CenterItr);

		// �����`�F�b�N
		auto TestItr = pList->GetEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	//*** �擪�v�f���폜���āA�����v�f���m�F����
	{
		// �擪�v�f���폜
		auto BeginItr = pList->GetBegin();
		pList->Delete(BeginItr);

		// �����`�F�b�N
		auto TestItr = pList->GetEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	//*** �����v�f���폜���āA�����v�f���m�F����
	{
		// �����v�f���폜
		auto EndItr = pList->GetEnd();
		--EndItr;
		pList->Delete(EndItr);

		// �����`�F�b�N
		auto TestItr = pList->GetEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** �����R���X�g�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:41
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*			�_�~�[�m�[�h���w���C�e���[�^����ăf�[�^�ɃA�N�Z�X�����
*			Assert���������Astderr�� Reference To DummyNode ���܂ޕ�����
*			�o�͂����̂ŁAEXPECT_DEATH()�𗘗p���ăe�X�g���܂��B
*/
TEST(GetEndConstIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList<ScoreData> List;

	// �����R���X�g�C�e���[�^�̎擾�擾
	auto Itr = List.GetConstEnd();

	// �����`�F�b�N
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:42
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�����R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, When1ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��1���ǉ�
	ScoreData Data{ 42, "Test42" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	auto& TestData = *EndItr;
	EXPECT_EQ(42, TestData.Score);
	EXPECT_EQ("Test42", TestData.Name);
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:43
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, When2ItemExist)
{
	LinkedList<ScoreData> List;

	// �f�[�^��2���ǉ�
	ScoreData Data{ 1, "Test1" };
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data = { 0, "Test0" };
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	auto& TestData = *EndItr;
	EXPECT_EQ(1, TestData.Score);
	EXPECT_EQ("Test1", TestData.Name);
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:44
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			�擪, ����, �擪�ł������ł��Ȃ��ʒu�ɑ}��������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, WhenInsert)
{
	// ���X�g
	LinkedList<ScoreData> List;

	//*** �擪�Ƀf�[�^��}������
	{
		ScoreData Data{ 44, "Test44_Begin" };
		auto Itr = List.GetBegin();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���擾
		auto EndItr = List.GetConstEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

		// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(44, TestData.Score);
		EXPECT_EQ("Test44_Begin", TestData.Name);
	}

	//*** �����Ƀf�[�^��ǉ�����
	{
		ScoreData Data = { 45, "Test45_End" };
		auto Itr = List.GetEnd();
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���Ď擾
		auto EndItr = List.GetConstEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

		// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(45, TestData.Score);
		EXPECT_EQ("Test45_End", TestData.Name);
	}

	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	{
		ScoreData Data = { 46, "Test46_Center" };
		auto Itr = List.GetBegin();
		++Itr;
		ASSERT_TRUE(List.Insert(Itr, Data));

		// �����C�e���[�^���Ď擾
		auto EndItr = List.GetConstEnd();
		--EndItr;	// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�

		// �����`�F�b�N
		auto& TestData = *EndItr;
		EXPECT_EQ(45, TestData.Score);
		EXPECT_EQ("Test45_End", TestData.Name);
	}
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:45
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f, �����v�f, �擪�ł������ł��Ȃ��v�f���폜������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(GetEndConstIteratorF, WhenDelete)
{
	// ����(�擪�ł������ł��Ȃ�)�v�f���폜
	// �擪�v�f���폜
	// �����v�f���폜
	// �̏��Ŋm�F����B
	// �Ȃ̂ŁA�f�[�^��4�ȏ�K�v�ɂȂ邽�߂���1�ǉ�����B
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	// �擪�ł������ł��Ȃ��v�f���폜���āA�����v�f���m�F����
	{

		// �擪�C�e���[�^���擾���āA�擪�ł������ł��Ȃ��v�f�ɐi�߂�
		auto CenterItr = pList->GetBegin();
		++CenterItr;

		// �擪�ł������ł��Ȃ��v�f
		pList->Delete(CenterItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	//*** �擪�v�f���폜���āA�����v�f���m�F����
	{
		// �擪�v�f���폜
		auto BeginItr = pList->GetBegin();
		pList->Delete(BeginItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	//*** �����v�f���폜���āA�����v�f���m�F����
	{
		// �����v�f���폜
		auto EndItr = pList->GetEnd();
		--EndItr;
		pList->Delete(EndItr);

		// �����`�F�b�N
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// �K�؂ɒl���Q�Ƃł��Ȃ��̂őO�ɐi�߂�
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

}	// ex01_LinkedList
