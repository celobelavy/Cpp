/*
Banking System Ver 0.1
작성자 : 윤성우
내 용 : OOP 단계별 프로젝트의 기본 틀 구성

*/

#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

void ShowMenu();		// 메뉴출력
void MakeAccount();		// 계좌개설을 위한 함수
void DepositMoney();	// 입 금
void WithdrawMoney();	// 출 금
void ShowAllAccInfo();	// 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;		// 계좌번호
	int balance;	// 잔 액
	char cusName[NAME_LEN];		// 고객이름
} Account; 

Account accArr[100];		// Account 저장을 위한 배열
int accNum = 0;				// 저장된 Account 수

int main()
{
	int choice;
	
	while (1)
	{
		ShowMenu();
		std::cout << "선택 : ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "Illegal selection..." << std::endl;
		}
	}
	return 0;
}

void ShowMenu()
{
	std::cout << "------Menu-------" << std::endl;
	std::cout << "1. 개좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "이 름 : "; std::cin >> name;
	std::cout << "입금액 : "; std::cin >> balance;
	std::cout << std::endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney()
{
	int money;
	int id;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "입금액 : "; std::cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "출금액 : "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				std::cout << "잔액부족" << std::endl << std::endl;
				return;
 			}

			accArr[i].balance -= money;
			std::cout << "출금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "계좌ID : " << accArr[i].accID << std::endl;
		std::cout << "이름 : " << accArr[i].cusName << std::endl;
		std::cout << "잔액 : " << accArr[i].balance << std::endl;
	}
}