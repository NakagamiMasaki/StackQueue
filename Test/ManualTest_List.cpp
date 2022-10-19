/**
* @brief	�o�������X�g �蓮�e�X�g
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../StackQueue/LinkedList.h"
#include "ScoreData.h"
#include "ManualTest_List.h"

/**
* @namespace	ex01_LinkedList
* @brief		�o�������X�g�̃e�X�g
*/
namespace ex01_ManualTest
{

/**
* @brief	�f�[�^�����擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩
* @details	ID:8
*			�f�[�^�����擾�̃e�X�g�ł��B
*			const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�ΐ����ł��B
*/
TEST(GetDataNum, FunctionIsConst)
{
#ifdef LIST_GETSIZE_IS_CONST
	const LinkedList<ScoreData> List;
	EXPECT_EQ(0, List.GetSize());
#else
	SUCCEED();
#endif
}

/**
* @brief	�f�[�^�}���@�\�ɂ��āA��const�̃��\�b�h�ł��邩
* @details	ID:15
*			�f�[�^�}���擾�̃e�X�g�ł��B
*			��const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(InsertData, FunctionIsNotConst)
{
#ifdef LIST_INSERT_IS_NOT_CONST
	
	const LinkedList<ScoreData> List;
	auto Itr = List.GetConstBegin();

	ScoreData Data;
	Data.Score = 15;
	Data.Name = "Test15";

	EXPECT_TRUE(List.Insert(Itr, Data));
#else
	SUCCEED();
#endif
}

/**
* @brief	�f�[�^�폜�@�\�ɂ��āA��const�̃��\�b�h�ł��邩
* @details	ID:22
*			�f�[�^�폜�擾�̃e�X�g�ł��B
*			��const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(DeleteData, FunctionIsNotConst)
{
#ifdef LIST_DELETE_IS_NOT_CONST

	const LinkedList<ScoreData> List;
	auto Itr = List.GetConstBegin();
	EXPECT_TRUE(List.Delete(Itr));
#else
	SUCCEED();
#endif
}

/**
* @brief	const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
* @details	ID:28
*			�擪�C�e���[�^�擾�̃e�X�g�ł��B
*			��const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(GetBeginIterator, FunctionIsNotConst)
{
#ifdef LIST_GETBEGIN_IS_NOT_CONST

	const LinkedList<ScoreData> List;
	List.GetBegin();

#else
	SUCCEED();
#endif
}

/**
* @brief	const�Ȑ擪�C�e���[�^�擾�@�\�ɂ��āAconst�Ȋ֐����`�F�b�N
* @details	ID:34
*			�擪�C�e���[�^�擾�̃e�X�g�ł��B
*			const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�ΐ����ł��B
*/
TEST(GetBeginConstIterator, FunctionIsConst)
{
#ifdef LIST_GETCONSTBEGIN_IS_CONST

	const LinkedList<ScoreData> List;
	List.GetConstBegin();

#else
	SUCCEED();
#endif
}

/**
* @brief	const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
* @details	ID:40
*			�����C�e���[�^�擾�̃e�X�g�ł��B
*			��const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(GetEndIterator, FunctionIsNotConst)
{
#ifdef LIST_GETEND_IS_NOT_CONST

	const LinkedList<ScoreData> List;
	List.GetEnd();

#else
	SUCCEED();
#endif
}

/**
* @brief	const�Ȑ擪�C�e���[�^�擾�@�\�ɂ��āAconst�Ȋ֐����`�F�b�N
* @details	ID:34
*			�����C�e���[�^�擾�̃e�X�g�ł��B
*			const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C�����ʂ�ΐ����ł��B
*/
TEST(GetEndConstIterator, FunctionIsConst)
{
#ifdef LIST_GETCONSTEND_IS_CONST

	const LinkedList<ScoreData> List;
	List.GetConstEnd();

#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g���R�s�[�ł��Ȃ����Ƃ��m�F����
* @details	ID:ex0
*			���X�g�̃R�s�[�Ɋւ���e�X�g�ł��B
*			���X�g���R�s�[�֎~�ɂȂ��Ă��邱�Ƃ��m�F���܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(CopyList, NonCopyable)
{
#ifdef LIST_CANNOT_COPY
	
	LinkedList<ScoreData> List1;
	LinkedList<ScoreData> List2(List1);	// �R�s�[�R���X�g���N�^�Ăяo��

	// �R�s�[����������Ă݂�
	List2 = List1;

#else
	SUCCEED();
#endif
}

/**
* @brief	���X�g�����[�u�ł��Ȃ����Ƃ��m�F����
* @details	ID:ex1
*			���X�g�̃��[�u�Ɋւ���e�X�g�ł��B
*			���X�g�����[�u�֎~�ɂȂ��Ă��邱�Ƃ��m�F���܂��B
*			�L���ɂ������A�R���p�C�����ʂ�Ȃ���ΐ����ł��B
*/
TEST(MoveList, NonMovable)
{
#ifdef LIST_CANNOT_MOVE

	LinkedList<ScoreData> List1;
	LinkedList<ScoreData> List2(std::move(List1));	// ���[�u�R���X�g���N�^�Ăяo��

	// ���[�u����������Ă݂�
	List2 = std::move(List1);

#else
	SUCCEED();
#endif
}


}	// ex01_ManualTest