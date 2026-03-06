#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion, int* p_AttackPotion, int* p_ArmorPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
	*p_AttackPotion = count;
	*p_ArmorPotion = count;
}
void setLevel(int up, int* l_Level) {
	*l_Level = up;

}

int main()
{
	system("chcp 65001");
	const int SIZE = 4;

	int stat[SIZE] = { 0 };
	int* i = stat;

	while (1) {
		cout << "HP와 MP를 입력해주세요." << endl;
		cin >> *i >> *(i + 1);

		if (*i >= 50 && *(i + 1) >= 50) {
			break;
		}
		cout << "HP와 MP의 값은 50 이상이어야 합니다. 다시 입력해주세요." << endl;
	}

	while (1) {
		cout << "공격력과 방어력을 입력해주세요." << endl;
		cin >> *(i + 2) >> *(i + 3);

		if (*(i + 2) >= 10 && *(i + 3) >= 10) {
			break;
		}
		cout << "공격력과 방어력의 값은 10 이상이어야 합니다. 다시 입력해주세요." << endl;
	}

	int choice = 0;
	int HPPotion = 0;
	int MPPotion = 0;
	int AttackPotion = 0;
	int ArmorPotion = 0;
	setPotion(5, &HPPotion, &MPPotion, &AttackPotion, &ArmorPotion);

	int Level = 0;
	setLevel(1, &Level);

	cout << "포션이 지급 되었습니다. (HP, MP, 공격력, 방어력 포션 각 5개씩)" << endl
		<< "============================================" << endl;
	cout << "스탯 관리 시스템" << endl
		<< "0번 프로그램 종료" << endl
		<< "1번 HP 회복" << endl
		<< "2번 MP 회복" << endl
		<< "3번 공격력 증가" << endl
		<< "4번 방어력 증가" << endl
		<< "5번 현재 상태창" << endl
		<< "6번 레벨업(포션 1개 증가)" << endl;

	while (1) {
		cout << "번호를 선택해주세요. : ";
		cin >> choice;

		if (choice == 0) {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}

		switch (choice) {
		case 1:
			if (HPPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			*i += 20;
			HPPotion--;

			cout << "HP가 20 증가되었습니다. 포션이 1개 차감 됩니다." << endl
				<< "현재 HP : " << *i << endl
				<< "남은 포션 수 : " << HPPotion << endl;

			break;

		case 2:
			if (MPPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			*(i + 1) += 20;
			MPPotion--;

			cout << "MP가 20 증가되었습니다. 포션이 1개 차감 됩니다." << endl
				<< "현재 MP : " << *(i + 1) << endl
				<< "남은 포션 수 : " << MPPotion << endl;

			break;

		case 3:
			if (AttackPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			*(i + 2) *= 2;
			AttackPotion--;

			cout << "공격력이 2배 증가되었습니다." << endl
				<< "현재 공격력 : " << *(i + 2) << endl
				<< "남은 포션 수 : " << AttackPotion << endl;

			break;

		case 4:
			if (ArmorPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			*(i + 3) *= 2;
			ArmorPotion--;
			cout << "방어력이 2배 증가되었습니다." << endl
				<< "현재 방어력 : " << *(i + 3) << endl
				<< "남은 포션 수 : " << ArmorPotion << endl;

			break;

		case 5:
			cout << "Level : " << Level << endl
				<< "HP : " << *i << endl
				<< "MP : " << *(i + 1) << endl
				<< "공격력 : " << *(i + 2) << endl
				<< "방어력 : " << *(i + 3) << endl;
			cout << "HP 포션 : " << HPPotion << endl
				<< "MP 포션 : " << MPPotion << endl
				<< "공격력 포션 : " << AttackPotion << endl
				<< "방어력 포션 : " << ArmorPotion << endl;

			break;

		case 6:
			Level++;
			HPPotion++;
			MPPotion++;
			AttackPotion++;
			ArmorPotion++;

			cout << "레벨이 1 증가하였습니다. 현재 레벨 : " << Level << endl
				<< "포션을 1개씩 지급합니다." << endl;

			break;

		default:
			cout << "잘못된 번호 입니다. 0~6번 중에 다시 입력해주세요." << endl;

			break;

		}
	}
	return 0;
}