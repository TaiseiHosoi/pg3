#include<stdio.h>

int GeneralWageCalculation(int hour, int hourlyPay) {

	if (hour <= 0) {
		return 0;
	}

	return hour * hourlyPay;
}

int RecursiveWage(int hour, int oldHour , int wage, int hourlyPay) {
	
	if (hour >= oldHour) {
		return wage;
	}

	return RecursiveWage(hour+1, oldHour,wage * 2 - 50, hourlyPay);
}

int main() {

	const int hourlyPay = 1072;
	const int recursivePay = 100;
	int oldHour = 0;
	int hour = 0;

	while (true)
	{
		
		int nowHourlyPay = GeneralWageCalculation(oldHour, hourlyPay);
		int nowRecursivePay = RecursiveWage(hour,oldHour, recursivePay, nowHourlyPay);

		printf("��ʓI:%d�@����%d  ", nowHourlyPay, oldHour);
		printf("�ċA�I:%d  ����%d\n", nowRecursivePay,oldHour);

		if (nowHourlyPay < nowRecursivePay && oldHour > 0) {	//0���Ԃ̎��_�ł�break���Ȃ�

			printf("%d���Ԃ̎��_�ōċA�I�Ȓ�������ʓI�Ȓ����𒴂���\n",oldHour);
			break;
		}

		oldHour++;
		
	}
	
	return 0;
}