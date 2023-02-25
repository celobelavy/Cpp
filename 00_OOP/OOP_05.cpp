/*
Banking System Ver 0.5
작성자 : 윤성우
내 용 : OOP 단계별 프로젝트의 기본 틀 구성

*/

#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

/*
* 클래스 이름 : Account
* 클래스 유형 : Entity 클래스
*/
class Account
{
private:
	int accID;	// 계좌번호
	int balance;	// 잔 액
	char * cusName;	// 고객이름
public:
	Account(int ID, int money, char * name);

	Account(const Account & ref);

	int GetAccID() const;

	void Desposit(int money);
	int Withdraw(int money);	// 출금액 반환, 부족 시 0 반환

	void ShowAccInfo() const;

	~Account();
};

Account::Account(int ID, int money, char * name) : accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account & ref) : accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Desposit(int money)
{
	balance += money;
}
	
int Account::Withdraw(int money)	// 출금액 반환, 부족 시 0 반환
{
	if(balance < money )
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	std::cout << "계좌 ID : " << accID << std::endl;
	std::cout << "이 름 : " << cusName << std::endl;
	std::cout << "잔 액 : " << balance << std::endl;
}

Account::~Account()
{
	delete []cusName;
}

/*
* 클래스 이름 : AccountHanlder
* 클래스 유형 : 컨트롤(control) 클래스
*/

class AccountHandler
{
private:
	Account * accArr[100];		// Account 저장을 위한 배열
	int accNum;		// 저장된 Account 수
public:
	AccountHandler();
	void ShowMenu() const;		// 메뉴출력
	void MakeAccount();		// 계좌개설을 위한 함수
	void DepositMoney();	// 입 금
	void WithdrawMoney();	// 출 금
	void ShowAllAccInfo() const;	// 잔액조회
	~AccountHandler();
};

void AccountHandler::ShowMenu() const
{
	std::cout << "------Menu-------" << std::endl;
	std::cout << "1. 개좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void AccountHandler::MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "이 름 : "; std::cin >> name;
	std::cout << "입금액 : "; std::cin >> balance;
	std::cout << std::endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "입금액 : "; std::cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Desposit(money);
			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌ID : "; std::cin >> id;
	std::cout << "출금액 : "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money)==0)
			{
				std::cout << "잔액부족" << std::endl << std::endl;
				return;
 			}
			std::cout << "출금완료" << std::endl << std::endl;
		}
	}
	std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		std::cout << std::endl;
	}
}

AccountHandler::~AccountHandler()
{
	for(int i=0; i<accNum; i++)
		delete accArr[i];
}

/*
* 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
*/
int main()
{
	AccountHandler manager;
	int choice;

	while(1)
	{
		manager.ShowMenu();
		std::cout << "선택 : ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
			case MAKE:
				manager.MakeAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case INQUIRE:
				manager.ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				std::cout << "Illegal selection.." << std::endl;

		}
	}

	return 0;
}

