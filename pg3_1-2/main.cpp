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

		printf("一般的:%d　時間%d  ", nowHourlyPay, oldHour);
		printf("再帰的:%d  時間%d\n", nowRecursivePay,oldHour);

		if (nowHourlyPay < nowRecursivePay && oldHour > 0) {	//0時間の時点ではbreakしない

			printf("%d時間の時点で再帰的な賃金が一般的な賃金を超える\n",oldHour);
			break;
		}

		oldHour++;
		
	}
	
	return 0;
}