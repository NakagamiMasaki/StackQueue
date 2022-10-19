/**
* @brief	�X�^�b�N�̃e�X�g
* @date		2022/10/17
*/

#include "gtest/gtest.h"
#include "../StackQueue/Stack.h"

//===== ���O��� =====
/**
* @brief	�X�^�b�N�̎����e�X�g
*/
namespace ex05_Stack
{

//===== �N���X��` =====
/**
* @brief	�X�^�b�N�̃e�X�g�p�t�B�N�X�`��
*			�͂��߂���3���f�[�^���ǉ����ꂽ�L���[�������o�Ɏ���
*/
class StackFixture : public ::testing::Test
{
protected:

	// �f�[�^��3�������Ă���X�^�b�N
	// �O���珇��0, 1, 2�Ɠ���
	// �Ȃ̂Ń|�b�v�����2, 1, 0�Əo�Ă���
	Stack<int> m_Stack;	

protected:

	void SetUp(void)
	{
		// �f�[�^��ǉ�
		m_Stack.Push(0);
		m_Stack.Push(1);
		m_Stack.Push(2);
	}

	void TearDown(void)
	{
	}
};

//===== �^�G�C���A�X ======
using StackPushF = StackFixture;
using StackPopF  = StackFixture;

#pragma region ***** �f�[�^���̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�̖߂�l
* @details	ID: �X�^�b�N-0
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			���X�g����̎��ɌĂяo�������̋������`�F�b�N���܂�
*			0���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, NoItem)
{
	Stack<int> stack;

	// �����`�F�b�N
	EXPECT_EQ(0, stack.GetSize());
}

/**
* @brief	�v�f���v�b�V��������̖߂�l
* @details	ID: �X�^�b�N-1
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			�v�f���v�b�V���������ƂɌĂяo�������̋������`�F�b�N���܂�
*			1���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, OneItemExist)
{
	Stack<int> stack;

	// �f�[�^��1���ǉ�����
	ASSERT_TRUE(stack.Push(0));

	// �����`�F�b�N
	EXPECT_EQ(1, stack.GetSize());
}

/**
* @brief	�v�f���|�b�v������̖߂�l
* @details	ID: �X�^�b�N-2
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			�v�f���|�b�v�������ƂɌĂяo�������̋������`�F�b�N���܂�
*			0���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, AfterPop)
{
	Stack<int> stack;

	// �v�b�V������
	ASSERT_TRUE(stack.Push(0));

	// �|�b�v����
	int Ret = 0;
	ASSERT_TRUE(stack.Pop(Ret));

	// �����`�F�b�N
	EXPECT_EQ(0, stack.GetSize());
}

/**
* @brief	�v�f�̃v�b�V���Ɏ��s������̖߂�l
* @details	ID: �X�^�b�N-3
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			�v�f�̃v�b�V���Ɏ��s�������ƂɌĂяo�������̋������`�F�b�N���܂�
*			0���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, AfterPushFailed)
{
	//*** �v�b�V���Ɏ��s����̂̓��������蓖�ĂɎ��s�������Ȃ̂ŁA�X�L�b�v
#if 1
	SUCCEED();
#else
	Stack<int> stack;

	// �v�b�V������
	ASSERT_FALSE(stack.Push(0));

	// �����`�F�b�N
	EXPECT_EQ(0, stack.GetSize());
#endif
}

/**
* @brief	�v�b�V����2��s������̖߂�l
* @details	ID: �X�^�b�N-4
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			�v�b�V����2��s�������ƂɌĂяo�������̋������`�F�b�N���܂�
*			2���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, AfterPushSecondTime)
{
	Stack<int> stack;

	// 2��v�b�V������
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));

	// �����`�F�b�N
	EXPECT_EQ(2, stack.GetSize());
}

/**
* @brief	�v�b�V����2��s������A�P��|�b�v������̖߂�l
* @details	ID: �X�^�b�N-5
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			�v�b�V����2��s�������ƁA1��|�b�v������ɌĂяo�������̋������`�F�b�N���܂�
*			1���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, AfterPushSecondPop)
{
	Stack<int> stack;

	// 2��v�b�V������
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));

	// 1��|�b�v����
	int Ret = 0;
	ASSERT_TRUE(stack.Pop(Ret));

	// �����`�F�b�N
	EXPECT_EQ(1, stack.GetSize());
}

/**
* @brief	���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
* @details	ID: �X�^�b�N-6
*			�f�[�^�����̎擾�̃e�X�g�ł�
*			���X�g����̎��ɁA�|�b�v���s������ɌĂяo�������̋������`�F�b�N���܂�
*			1���Ԃ�ΐ����ł�
*/
TEST(StackGetSize, PopEmptyStack)
{
	Stack<int> stack;

	// 1��|�b�v����
	// ��Ȃ̂Ŏ��s����
	int Ret = 0;
	ASSERT_FALSE(stack.Pop(Ret));

	// �����`�F�b�N
	EXPECT_EQ(0, stack.GetSize());
}

#pragma endregion
#pragma region ***** �v�b�V�� *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
* @details	ID: �X�^�b�N-8
*			�v�b�V���̃e�X�g�ł�
*			���X�g����̎��ɁA�v�b�V�����s�������̋������`�F�b�N���܂�
*			true���Ԃ�ΐ����ł�
*/
TEST(StackPush, Empty)
{
	Stack<int> stack;

	// �����`�F�b�N
	EXPECT_TRUE(stack.Push(0));

	// �����ɒǉ�����Ă��邱���`�F�b�N
	// Stack��Pop()�͖���������o���̂�
	// Pop���Ċm�F���Ă݂�
	// �|�b�v����
	int Ret = -1;					// Pop���ē�����l��0�̂͂��Ȃ̂�-1�ŏ���������
	ASSERT_TRUE(stack.Pop(Ret));
	
	EXPECT_EQ(0, Ret);				// ����ꂽ�f�[�^���m�F����
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
* @details	ID: �X�^�b�N-9
*			�v�b�V���̃e�X�g�ł�
*			���X�g�ɕ����̗v�f�����鎞�ɁA�v�b�V�����s�������̋������`�F�b�N���܂�
*			true���Ԃ�ΐ����ł�
*/
TEST_F(StackPushF, SomeDataExist)
{
	// �����`�F�b�N
	EXPECT_TRUE(m_Stack.Push(3));

	// �����ɒǉ�����Ă��邱�Ƃ��`�F�b�N
	// Stack��Pop()�͖���������o���̂�
	// Pop���Ċm�F���Ă݂�
	// �|�b�v����
	int Ret = -1;					// Pop���ē�����l��3�̂͂��Ȃ̂�-1�ŏ���������
	ASSERT_TRUE(m_Stack.Pop(Ret));
	
	EXPECT_EQ(3, Ret);				// ����ꂽ�f�[�^���m�F����
}

#pragma endregion
#pragma region ***** �|�b�v *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
* @details	ID: �X�^�b�N-11
*			�|�b�v�̃e�X�g�ł�
*			���X�g����̎��ɁA�|�b�v���s�������̋������`�F�b�N���܂�
*			false���Ԃ�ΐ����ł�
*/
TEST(StackPop, Empty)
{
	Stack<int> stack;

	// �|�b�v����
	int Ret = 0;
	EXPECT_FALSE(stack.Pop(Ret));

	// �v�f���ɕω����Ȃ����Ƃ��m�F����
	EXPECT_EQ(0, stack.GetSize());
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
* @details	ID: �X�^�b�N-12
*			�|�b�v�̃e�X�g�ł�
*			���X�g�ɕ����̗v�f�����鎞�ɁA�|�b�v���s�������̋������`�F�b�N���܂�
*			true���Ԃ�ΐ����ł�
*/
TEST_F(StackPopF, SomeItemExist)
{

	// �f�[�^��3�����邱�Ƃ��m�F����
	ASSERT_EQ(3, m_Stack.GetSize());

	// �|�b�v����
	int Ret = 0;
	EXPECT_TRUE(m_Stack.Pop(Ret));

	// ����(2)�������Ă��邱�Ƃ��m�F����
	EXPECT_EQ(2, Ret);

	// �f�[�^��2���ɂȂ��Ă��邱�Ƃ��m�F����
	EXPECT_EQ(2, m_Stack.GetSize());
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
* @details	ID: �X�^�b�N-13
*			�|�b�v�̃e�X�g�ł�
*			���X�g�ɕ����̗v�f�����鎞�ɁA�|�b�v���s�������̋������`�F�b�N���܂�
*			true���Ԃ�ΐ����ł�
*/
TEST_F(StackPopF, Pop)
{
	// �f�[�^��3�����邱�Ƃ��m�F����
	ASSERT_EQ(3, m_Stack.GetSize());

	int TestData[3] = { 2, 1, 0 };

	// �|�b�v����
	for (int i = 0; i < 3; ++i)
	{
		int Ret = -1;
		EXPECT_TRUE(m_Stack.Pop(Ret));
		EXPECT_EQ(TestData[i], Ret);
	}

	// �f�[�^��0���ɂȂ��Ă��邱�Ƃ��m�F����
	EXPECT_EQ(0, m_Stack.GetSize());
}

#pragma endregion

}	// ex05_Stack
