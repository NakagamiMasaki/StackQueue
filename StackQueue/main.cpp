/**
* @brief	スタック・キュー 実装課題
* @date		2022/10/17
*/

//===== インクルード =====
#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

/**
* @brief	エントリーポイント
* @retval	0    成功
* @retval	0以外 失敗
*/
int main(void)
{
	LinkedList<int> List;

	auto Itr = List.GetEnd();
	List.Insert(Itr, 4);
	List.Insert(Itr, 2);
	List.Insert(Itr, 0);
	List.Insert(Itr, 3);
	List.Insert(Itr, 4);
	List.Insert(Itr, 0);
	List.Insert(Itr, 1);
	List.Insert(Itr, 0);
	List.Insert(Itr, 5);

	List.Quicksort(std::greater<int>());

	for (Itr = List.GetBegin(); Itr != List.GetEnd(); ++Itr)
	{
		std::cout << *Itr << std::endl;
	}

	std::cin.sync();
	std::cin.get();

	return 0;
}
