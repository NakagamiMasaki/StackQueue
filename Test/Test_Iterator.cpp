/**
* @brief	�C�e���[�^�̒P�̃e�X�g�p
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../StackQueue/LinkedList.h"
#include "ScoreData.h"
#include "TestHelper.h"

/**
* @namespace	ex02_Iterator
* @brief		�C�e���[�^�̃e�X�g
*/
namespace ex02_Iterator
{

//===== �^�G�C���A�X =====

using IteratorIncrementF       = LinkedListTestFixture;
using IteratorDecrementF       = LinkedListTestFixture;
using IteratorCopyConstractorF = LinkedListTestFixture;
using IteratorCopyAssignmentF  = LinkedListTestFixture;
using IteratorCompareEQF       = LinkedListTestFixture;
using IteratorCompareNEF       = LinkedListTestFixture;

#pragma region ***** �C�e���[�^�̎w���v�f���擾���� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:0
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��C�e���[�^����v�f�����o�����Ƃ������̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, InvalidReference)
{
#ifdef _DEBUG

	// ��R���X�g�C�e���[�^
	LinkedList<ScoreData>::Iterator Itr;
	EXPECT_DEATH(*Itr, ".*Invalid Reference.*");

	// �R���X�g�C�e���[�^
	LinkedList<ScoreData>::ConstIterator ConstItr;
	EXPECT_DEATH(*ConstItr, ".*Invalid Reference.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
* @details	ID:1
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			�C�e���[�^����擾�����v�f�ɑ�����ł��邩�̊m�F�����܂��B
*			�l�����������ƁA�Ăю擾�������Ƀf�[�^���ς���Ă����琬���ł��B
*/
TEST(GetIteratorData, AfterAssignment)
{
	// 1���f�[�^��ǉ����Ă���
	LinkedList<ScoreData> List;
	ScoreData Data{ 0, "Test0" };
	auto EndItr = List.GetEnd();
	List.Insert(EndItr, Data);

	// �l��������
	auto Itr = List.GetBegin();
	auto& Element = *Itr;
	Element = { 1, "Test1" };

	// �C�e���[�^���擾���Ȃ����Ċm�F����
	Itr = List.GetBegin();
	auto& TestData = *Itr;
	EXPECT_EQ(1, TestData.Score);
	EXPECT_EQ("Test1", TestData.Name);
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:3
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�擪�C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, EmptyListBeginIterator)
{
#ifdef _DEBUG
	// ��̃��X�g��p�ӂ���
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetBegin();
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");

	// �R���X�g�C�e���[�^���擾���Ċm�F����
	auto ConstItr = List.GetConstBegin();
	EXPECT_DEATH(*ConstItr, ".*Reference To DummyNode.*");

#else
	SUCCEED();
#endif
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:4
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�����C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, EndIterator)
{
#ifdef _DEBUG
	// ��̃��X�g��p�ӂ���
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetEnd();
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");

	// �R���X�g�C�e���[�^���擾���Ċm�F����
	auto ConstItr = List.GetConstEnd();
	EXPECT_DEATH(*ConstItr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

#pragma endregion

#pragma region ***** �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:5
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, InvalidReference)
{
#ifdef _DEBUG

	// ��R���X�g�C�e���[�^
	LinkedList<ScoreData>::Iterator Itr;
	EXPECT_DEATH(++Itr, ".*Invalid Reference.*");

	// �R���X�g�C�e���[�^
	LinkedList<ScoreData>::ConstIterator ConstItr;
	EXPECT_DEATH(++ConstItr, ".*Invalid Reference.*");

#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:6
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, EmptyListBeginIterator)
{
#ifdef _DEBUG

	// ��̃��X�g��p�ӂ���
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	auto Itr = List.GetBegin();
	EXPECT_DEATH(++Itr, ".*This Iterator Is End.*");	// �v�f����0�Ȃ疖���C�e���[�^���Ԃ�̂𗘗p����

	// �R���X�g�C�e���[�^
	auto ConstItr = List.GetConstBegin();
	EXPECT_DEATH(++ConstItr, ".*This Iterator Is End.*");	// �v�f����0�Ȃ疖���C�e���[�^���Ԃ�̂𗘗p����

#else
	SUCCEED();
#endif
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:7
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�����C�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, EndIterator)
{
#ifdef _DEBUG

	// ��̃��X�g��p�ӂ���
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	auto Itr = List.GetEnd();
	EXPECT_DEATH(++Itr, ".*This Iterator Is End.*");

	// �R���X�g�C�e���[�^
	auto ConstItr = List.GetConstEnd();
	EXPECT_DEATH(++ConstItr, ".*This Iterator Is End.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:8
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
*/
TEST_F(IteratorIncrementF, BeginToEnd)
{
	ScoreData TestData[3] = {
		{ 0, "Test0" },
		{ 1, "Test1" },
		{ 2, "Test2" }
	};

	// �R���X�g�C�e���[�^
	auto Itr = pList->GetBegin();
	for (int i = 0; i < 3; ++i)
	{
		auto& Data = *Itr;

		// ���������`�F�b�N
		EXPECT_EQ(TestData[i].Score, Data.Score);
		EXPECT_EQ(TestData[i].Name, Data.Name);

		++Itr;
	}

	// ��R���X�g�C�e���[�^
	auto ConstItr = pList->GetConstBegin();
	for (int i = 0; i < 3; ++i)
	{
		auto& Data = *ConstItr;

		// ���������`�F�b�N
		EXPECT_EQ(TestData[i].Score, Data.Score);
		EXPECT_EQ(TestData[i].Name, Data.Name);

		++ConstItr;
	}
}

/**
* @brief	�O�u�C���N�������g���s�����ۂ̋���
* @details	ID:9
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(IteratorIncrementF, PrefixIncrement)
{
	// ��R���X�g�C�e���[�^
	{
		// �擪�C�e���[�^
		auto Itr = pList->GetBegin();

		EXPECT_EQ(1, (*(++Itr)).Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
		EXPECT_EQ(1, (*Itr).Score);		// �����w���Ă��邩�`�F�b�N
	}

	// �R���X�g�C�e���[�^
	{
		// �擪�C�e���[�^
		auto ConstItr = pList->GetConstBegin();

		EXPECT_EQ(1, (*(++ConstItr)).Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
		EXPECT_EQ(1, (*ConstItr).Score);		// �����w���Ă��邩�`�F�b�N
	}
}

/**
* @brief	��u�C���N�������g���s�����ۂ̋���
* @details	ID:10
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(IteratorIncrementF, PostfixIncrement)
{
	// ��R���X�g�C�e���[�^
	{
		// �擪�C�e���[�^
		auto Itr = pList->GetBegin();

		EXPECT_EQ(0, (*(Itr++)).Score);	// ��u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
		EXPECT_EQ(1, (*Itr).Score);		// �����w���Ă��邩�`�F�b�N
	}

	// �R���X�g�C�e���[�^
	{
		// �擪�C�e���[�^
		auto ConstItr = pList->GetConstBegin();

		EXPECT_EQ(0, (*(ConstItr++)).Score);	// ��u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
		EXPECT_EQ(1, (*ConstItr).Score);		// �����w���Ă��邩�`�F�b�N
	}
}

#pragma endregion

#pragma region ***** �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:11
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, InvalidReference)
{
#ifdef _DEBUG

	// ��R���X�g�C�e���[�^
	LinkedList<ScoreData>::Iterator Itr;
	EXPECT_DEATH(--Itr, ".*Invalid Reference.*");

	// �R���X�g�C�e���[�^
	LinkedList<ScoreData>::ConstIterator ConstItr;
	EXPECT_DEATH(--ConstItr, ".*Invalid Reference.*");

#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:12
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�擪�Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, EmptyListBeginIterator)
{
#ifdef _DEBUG
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	auto Itr = List.GetEnd();
	EXPECT_DEATH(--Itr, ".*This Iterator Is Begin.*");

	// �R���X�g�C�e���[�^
	auto ConstItr = List.GetConstEnd();
	EXPECT_DEATH(--Itr, ".*This Iterator Is Begin.*");

#else
	SUCCEED();
#endif
}

/**
* @brief	�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:13
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�擪�C�e���[�^��擪�Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, EndIterator)
{
#ifdef _DEBUG

	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	auto Itr = List.GetBegin();
	EXPECT_DEATH(--Itr, ".*This Iterator Is Begin.*");

	// �R���X�g�C�e���[�^
	auto ConstItr = List.GetConstBegin();
	EXPECT_DEATH(--ConstItr, ".*This Iterator Is Begin.*");

#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:14
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
*/
TEST_F(IteratorDecrementF, EndToBegin)
{
	ScoreData TestData[3] = {
		{ 2, "Test2" },
		{ 1, "Test1" },
		{ 0, "Test0" }
	};

	// ��R���X�g�C�e���[�^
	{
		auto Itr = pList->GetEnd();
		for (int i = 0; i < 3; ++i)
		{
			--Itr;

			auto& Data = *Itr;

			// ���������`�F�b�N
			EXPECT_EQ(TestData[i].Score, Data.Score);
			EXPECT_EQ(TestData[i].Name, Data.Name);
		}
	}

	// �R���X�g�C�e���[�^
	{
		auto Itr = pList->GetConstEnd();
		for (int i = 0; i < 3; ++i)
		{
			--Itr;

			auto& Data = *Itr;
			EXPECT_EQ(TestData[i].Score, Data.Score);
			EXPECT_EQ(TestData[i].Name, Data.Name);
		}
	}
}

/**
* @brief	�O�u�f�N�������g�s�����ۂ̋���
* @details	ID:15
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(IteratorDecrementF, PrefixDecrement)
{
	// ��R���X�g�Ȗ����C�e���[�^
	auto Itr = pList->GetEnd();

	EXPECT_EQ(2, (*(--Itr)).Score);	// �O�u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(2, (*Itr).Score);		// �O���w���Ă��邩�`�F�b�N

	// �R���X�g�Ȗ����C�e���[�^
	auto ConstItr = pList->GetConstEnd();

	EXPECT_EQ(2, (*(--ConstItr)).Score);	// �O�u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(2, (*ConstItr).Score);		// �O���w���Ă��邩�`�F�b�N
}

/**
* @brief	��u�f�N�������g���s�����ۂ̋���
* @details	ID:16
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(IteratorDecrementF, PostfixDecrement)
{
	// ��R���X�g�C�e���[�^
	{
		// �����C�e���[�^
		auto Itr = pList->GetEnd();

		--Itr;	// �����Ńf�N�������g���Ă����Ȃ��ƃ_�~�[�m�[�h�ɃA�N�Z�X���Ă��܂�

		EXPECT_EQ(2, (*(Itr--)).Score);	// ��u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
		EXPECT_EQ(1, (*Itr).Score);		// �O���w���Ă��邩�`�F�b�N
	}

	// �R���X�g�C�e���[�^
	{
		// �����C�e���[�^
		auto ConstItr = pList->GetConstEnd();

		--ConstItr;	// �����Ńf�N�������g���Ă����Ȃ��ƃ_�~�[�m�[�h�ɃA�N�Z�X���Ă��܂�

		EXPECT_EQ(2, (*(ConstItr--)).Score);	// ��u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
		EXPECT_EQ(1, (*ConstItr).Score);		// �O���w���Ă��邩�`�F�b�N
	}
}

#pragma endregion

#pragma region ***** �C�e���[�^�̃R�s�[���s�� *****

/**
* @brief	�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:18
*			�R�s�[�R���X�g���N�^�ŃR�s�[�����C�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(IteratorCopyConstractorF, CopyConstractor)
{
	// ��R���X�g�C�e���[�^
	{
		auto Itr = pList->GetBegin();

		// �R�s�[
		LinkedList<ScoreData>::Iterator CopyItr(Itr);

		// �`�F�b�N
		EXPECT_TRUE(CopyItr == Itr);
	}

	// �R���X�g�C�e���[�^
	{
		auto ConstItr = pList->GetConstBegin();

		// �R�s�[
		LinkedList<ScoreData>::ConstIterator CopyItr(ConstItr);

		// �`�F�b�N
		EXPECT_TRUE(CopyItr == ConstItr);
	}
}

#pragma endregion

#pragma region ***** �C�e���[�^�̑�����s�� *****

/**
* @brief	�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:20
*			�R�s�[����łŃR�s�[�����C�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(IteratorCopyAssignmentF, CopyAssignment)
{
	// ��R���X�g�C�e���[�^
	{
		auto Itr = pList->GetBegin();

		// �R�s�[
		LinkedList<ScoreData>::Iterator CopyItr;
		CopyItr = Itr;

		// �`�F�b�N
		EXPECT_TRUE(CopyItr == Itr);
	}

	// �R���X�g�C�e���[�^
	{
		auto Itr = pList->GetConstBegin();

		// �R�s�[
		LinkedList<ScoreData>::ConstIterator CopyItr;
		CopyItr = Itr;

		// �`�F�b�N
		EXPECT_TRUE(CopyItr == Itr);
	}
}

#pragma endregion

#pragma region ***** 2�̃C�e���[�^������̂��̂ł��邩��r���s�� *****

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:21
*			��̃��X�g����擾�����擪�C�e���[�^�Ɩ����C�e���[�^���r����e�X�g�ł��B
*			true���Ԃ�ΐ����ł��B
*/
TEST(IteratorCompareEQ, EmptyListBeginAndEnd)
{
	// ��̃��X�g��p�ӂ���
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = List.GetBegin();
		auto EndItr = List.GetEnd();

		// ����ł��邩�m�F
		EXPECT_TRUE(BeginItr == EndItr);
	}

	// �R���X�g�C�e���[�^
	{
		auto BeginItr = List.GetConstBegin();
		auto EndItr = List.GetConstEnd();

		// ����ł��邩�m�F
		EXPECT_TRUE(BeginItr == EndItr);
	}
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:22
*			����̃C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(IteratorCompareEQF, SameIterator)
{
	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetBegin();
		auto Itr = pList->GetBegin();

		// ����ł��邩�m�F
		EXPECT_TRUE(BeginItr == Itr);
	}

	// �R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetConstBegin();
		auto Itr = pList->GetConstBegin();

		// ����ł��邩�m�F
		EXPECT_TRUE(BeginItr == Itr);
	}
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:23
*			�قȂ�C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(IteratorCompareEQF, DiffrentIterator)
{
	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetBegin();
		auto Itr = pList->GetBegin();

		++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

		// ����ł��邩�m�F
		EXPECT_FALSE(BeginItr == Itr);
	}

	// �R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetConstBegin();
		auto Itr = pList->GetConstBegin();

		++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

		// ����ł��邩�m�F
		EXPECT_FALSE(BeginItr == Itr);
	}
}

#pragma endregion

#pragma region ***** 2�̃C�e���[�^���قȂ�̂��̂ł��邩��r���s�� *****

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:24
*			��̃��X�g����擾�����擪�C�e���[�^�Ɩ����C�e���[�^���r����e�X�g�ł��B
*			false���Ԃ�ΐ����ł��B
*/
TEST(IteratorCompareNE, EmptyListBeginAndEnd)
{
	// ��̃C�e���[�^
	LinkedList<ScoreData> List;

	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = List.GetBegin();
		auto EndItr = List.GetEnd();

		// �قȂ邩�m�F
		EXPECT_FALSE(BeginItr != EndItr);
	}

	// �R���X�g�C�e���[�^
	{
		auto BeginItr = List.GetConstBegin();
		auto EndItr = List.GetConstEnd();

		// �قȂ邩�m�F
		EXPECT_FALSE(BeginItr != EndItr);
	}
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:25
*			����̃C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(IteratorCompareNEF, SameIterator)
{
	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetBegin();
		auto Itr = pList->GetBegin();

		// �قȂ邩�m�F
		EXPECT_FALSE(BeginItr != Itr);
	}

	// �R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetConstBegin();
		auto Itr = pList->GetConstBegin();

		// �قȂ邩�m�F
		EXPECT_FALSE(BeginItr != Itr);
	}
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:26
*			�قȂ�C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(IteratorCompareNEF, DiffrentIterator)
{
	// �R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetBegin();
		auto Itr = pList->GetBegin();

		++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

		// �قȂ邩�m�F
		EXPECT_TRUE(BeginItr != Itr);
	}

	// ��R���X�g�C�e���[�^
	{
		auto BeginItr = pList->GetConstBegin();
		auto Itr = pList->GetConstBegin();

		++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

		// �قȂ邩�m�F
		EXPECT_TRUE(BeginItr != Itr);
	}
}

#pragma endregion

}	// ex02_Iterator