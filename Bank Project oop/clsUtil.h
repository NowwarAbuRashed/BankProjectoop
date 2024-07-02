#pragma once
#include<iostream>
using namespace std;


class clsUtil
{

private:


protected:



public:


	static string Tabe(short Size)
	{
		string T = "";
		while (Size--)
		{
			T += "\t";
		}
		return T;
	}

	static bool CheckNumberItIs_Perfect_OrNot(int Number)
	{
		int sum = 0;
		int sqrtNumber = sqrt(Number);
		for (int i = 1; i <= sqrtNumber; i++)
		{
			if (Number % i == 0)
			{
				sum += i;
				if (i != 1)
					sum += Number / i;
			}
		}
		return sum == Number;
	}


	static void PrentPerfect_Numbers_From_1_To_N(int N)
	{
		for (int i = 2; i <= N; i++)
		{
			if (CheckNumberItIs_Perfect_OrNot(i))
				cout << i << endl;
		}
	}



	static void divide_TheNumber_On_N(int& Number, int Divide = 10)
	{
		Number /= Divide;
	}

	static int The_Remainder_Of_TheDivionNumber_by_N(int Number, int Remainder = 10)
	{
		return Number % Remainder;
	}

	static void Prent_Reversed_Order(int Number)
	{
		while (Number)
		{
			cout << The_Remainder_Of_TheDivionNumber_by_N(Number) << endl;
			divide_TheNumber_On_N(Number);
		}
	}

	static int Prent_ReversedNumber(int Number)
	{
		int  ReverseNumber = 0;
		while (Number)
		{
			ReverseNumber = ReverseNumber * 10 + The_Remainder_Of_TheDivionNumber_by_N(Number);
			divide_TheNumber_On_N(Number);
		}
		return ReverseNumber;
	}

	static void Print_DigitFrequncy_in_TheNumber(int Number, short Search)
	{
		short NumbersofN[10] = { 0 };
		while (Number)
		{
			NumbersofN[The_Remainder_Of_TheDivionNumber_by_N(Number)]++;
			divide_TheNumber_On_N(Number);
		}
		cout << "Digit " << Search << " Frequency is " << NumbersofN[Search] << " Time(s).\n";
	}

	static void Print_AllDigitFrequncy_in_TheNumber(int Number)
	{
		short NumbersofN[10] = { 0 };
		while (Number)
		{
			NumbersofN[The_Remainder_Of_TheDivionNumber_by_N(Number)]++;
			divide_TheNumber_On_N(Number);
		}
		for (short Search = 1; Search < 10; Search++)
			if (NumbersofN[Search] != 0)
				cout << "Digit " << Search << " Frequency is " << NumbersofN[Search] << " Time(s).\n";
	}


	static int ReverseNumber(int Number)
	{
		int Number2 = 0;
		while (Number)
		{
			Number2 = Number2 * 10 + The_Remainder_Of_TheDivionNumber_by_N(Number);
			divide_TheNumber_On_N(Number);
		}
		return Number2;
	}

	static bool isPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

	static void Print_Inverted_Pattern(short Number)
	{
		for (short i = Number; i > 0; i--)
		{
			for (short j = i; j > 0; j--)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void Print_Number_Pattern(short Number)
	{
		for (short i = 1; i <= Number; i++)
		{
			for (short j = i; j > 0; j--)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void Print_Inverted_Letter_Pattern(short Number)
	{
		for (short i = Number; i > 0; i--)
		{
			for (short j = i; j > 0; j--)
			{
				cout << char(i + 64);
			}
			cout << endl;
		}
	}

	static void Print_Letter_Pattern(short Number)
	{
		for (short i = 1; i <= Number; i++)
		{
			for (short j = 1; j <= Number; j++)
			{
				for (short k = 1; k <= Number; k++)
				{
					cout << char(i + 64) << char(j + 64) << char(k + 64);
				}
			}
			cout << endl;
		}
	}

	static string  EncryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, Specialharacter = 4, MixChar = 5 };

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == MixChar)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::Digit:
		{
			return RandomNumber(48, 57);
			break;
		}
		case enCharType::Specialharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}


		}
	}

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static string Generate_Word(enCharType CharType, short Lingth)
	{
		string Word = "";
		for (int i = 1; i <= Lingth; i++)
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKeys(enCharType CharType)
	{
		string Keys = "";
		Keys = Generate_Word(CharType, 4) + '-';
		Keys += Generate_Word(CharType, 4) + '-';
		Keys += Generate_Word(CharType, 4) + '-';
		Keys += Generate_Word(CharType, 4);
		return Keys;
	}

	static void How_manyKeys_To_Generate(int Number, enCharType CharType)
	{
		for (int i = 1; i <= Number; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKeys(CharType) << endl;
		}
	}

	static void Read_N_Elements_And_StoreThem_In_Array(int Array[], int arrlingth)
	{
		cout << "Enter array elements:\n";
		for (int i = 0; i < arrlingth; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> Array[i];
		}
	}

	static void PrintAll_Array_Elements(int Array[], int Size)
	{
		for (int i = 0; i < Size; i++)
			cout << Array[i] << " ";
		cout << endl;
	}


	static void Number_freq(int Array[], short freq[], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			freq[Array[i]]++;
		}
	}

	static short TimesRepeated(int Number, short freq[])
	{
		return  freq[Number];
	}

	static void Fill_Array_With_RandomNumber(int Array[], int arrlingth, int From, int To)
	{
		for (int i = 0; i < arrlingth; i++)
		{
			Array[i] = RandomNumber(From, To);
		}
	}

	static void Fill_Array_With_RandomWords(string Array[], int arrlingth, enCharType CharType, short Size)
	{
		for (int i = 0; i < arrlingth; i++)
		{
			Array[i] = Generate_Word(CharType, Size);
		}
	}

	static enum enOddOrEven { Odd = 1, Even = 2 };

	static bool CheckTheNumber_Odd_Or_Even(int Number)
	{
		if (Number & 1)
			return enOddOrEven::Odd;
		else
			return enOddOrEven::Even;
	}

	static short CountNumberOf_Odd_In_Array(int Array[], int arrLingth)
	{
		int counter = 0;
		for (int i = 0; i < arrLingth; i++)
		{
			if (CheckTheNumber_Odd_Or_Even(Array[i]) == enOddOrEven::Odd)
				counter++;
		}
		return counter;
	}

	static int MaxNumber(int Array[], int arrlingth)
	{
		int Max = -1;
		for (int i = 0; i < arrlingth; i++)
		{
			if (Array[i] > Max)
				Max = Array[i];
		}
		return Max;
	}

	static int MinNumber(int arr[], int arrLingth)
	{
		int Min = arr[0];
		for (int i = 1; i < arrLingth; i++)
		{
			if (arr[i] < Min)
				Min = arr[i];
		}
		return Min;
	}

	static int SumArray(int arr[], int arrLingth)
	{
		int sum = 0;
		for (int i = 0; i < arrLingth; i++)
		{
			sum += arr[i];
		}
		return sum;
	}

	static float AveragArray(int arr[], short arrLingth)
	{
		return (float)SumArray(arr, arrLingth) / arrLingth;
	}

	static void CopyArray(int arrSource[], int arrDestination[], int Arrlingth)
	{
		for (int i = 0; i < Arrlingth; i++)
		{
			arrDestination[i] = arrSource[i];
		}
	}

	static enum enPirmNotPrime { Prime = 1, NotPrime = 2 };

	static enPirmNotPrime Check_PrimeNumber(int Number)
	{
		for (long i = 2; i * i <= Number; i++)
		{
			if (Number % i == 0)
			{
				return enPirmNotPrime::NotPrime;
			}
		}
		return enPirmNotPrime::Prime;

	}

	static void CopyOnlyPrimeNumber(int arrSource[], int arrDestination[], int Arrlingth, short arrLingth2)
	{
		for (short i = 0, indx = 0; i < Arrlingth; i++)
		{
			arrLingth2 = indx;
			if (Check_PrimeNumber(arrSource[i]) == enPirmNotPrime::Prime)
				arrDestination[indx++] = arrSource[i];
		}

	}

	static void SumOfArrays(int arr1[], int arr2[], int SumArr[], int arrLingth)
	{
		for (int i = 0; i < arrLingth; i++)
			SumArr[i] = arr1[i] + arr2[i];
	}

	static void Fill_Array_From_1_To_N(int Array[], int arrlingth)
	{
		for (int i = 0; i < arrlingth; i++)
		{
			Array[i] = i + 1;
		}
	}

	static void ShuffleArray(int Array[], int arrlingth)
	{
		for (int i = 0; i < arrlingth; i++)
		{
			swap(Array[RandomNumber(0, arrlingth - 1)], Array[RandomNumber(0, arrlingth - 1)]);
		}
	}

	static void ShuffleArray(string Array[], int arrlingth)
	{
		for (int i = 0; i < arrlingth; i++)
		{
			swap(Array[RandomNumber(0, arrlingth - 1)], Array[RandomNumber(0, arrlingth - 1)]);
		}
	}

	static void CopyArrayReverse(int arrSource[], int arrDestination[], int Arrlingth)
	{
		for (int i = 0; i < Arrlingth; i++)
		{
			arrDestination[Arrlingth - i - 1] = arrSource[i];
		}
	}

	static void Fill_Array_With_Keys(string Array[], enCharType CharType, int arrlingth)
	{

		for (int i = 0; i < arrlingth; i++)
		{
			Array[i] = GenerateKeys(CharType);
		}
	}

	static void PrintAll_Array_String(string Array[], short arrlingth)
	{
		for (int i = 0; i < arrlingth; i++)
			cout << "Array[" << i << "] : " << Array[i] << endl;
	}

	static int FindNumberPositionInArray(int arr[], int Number, int arrLingth)
	{
		for (int i = 0; i < arrLingth; i++)
		{
			if (arr[i] == Number)
				return i;
		}
		return -1;
	}

	static bool Number_found_InArray_Or_Not(int arr[], int NumberSearch, int arrLingth)
	{
		return FindNumberPositionInArray(arr, NumberSearch, arrLingth) != -1;

	}

	static void AddArrayElement(int Number, int Array[], int arrLingth)
	{
		Array[arrLingth++] = Number;
	}

	static void InputUserNumberInArray(int Number, int Array[], short arrLingth)
	{
		bool AddMore;
		do {
			AddArrayElement(Number, Array, arrLingth);
			cout << "\n Do you want to add more numbers?[0]:NO,[1]:Yes? ";
			cin >> AddMore;
		} while (AddMore);
	}

	static void CopyOddNumber_Using_AddArrayElement(int arrSource[], int arrDestination[], short ArrlingthSource, int ArrlingthDestination)
	{
		for (int i = 0; i < ArrlingthSource; i++)
			if (arrSource[i] & 1)
				AddArrayElement(arrSource[i], arrDestination, ArrlingthDestination);
	}

	static void CopyPrimeNumber_Using_AddArrayElement(int arrSource[], int arrDestination[], int ArrlingthSource, int ArrlingthDestination)
	{
		for (int i = 0; i < ArrlingthSource; i++)
			if (Check_PrimeNumber(arrSource[i]) == enPirmNotPrime::Prime)
				AddArrayElement(arrSource[i], arrDestination, ArrlingthDestination);
	}

	static void FillDistinctNumber_Using_AddArrayElement(int arrSource[], int arrDestination[], int ArrlingthSource, int ArrlingthDestination)
	{
		for (int i = 0; i < ArrlingthSource; i++)
			if (!Number_found_InArray_Or_Not(arrDestination, arrSource[i], ArrlingthDestination))
				AddArrayElement(arrSource[i], arrDestination, ArrlingthDestination);
	}

	static bool Check_If_It_Is_PalindromeArray_Or_Not(int Array[], int arrLingth)
	{
		for (int i = 0; i < arrLingth; i++)
		{
			if (Array[i] != Array[arrLingth - i - 1])
				return false;
		}
		return true;
	}

	static int CountNumberOf_Even_In_Array(int Array[], int arrLingth)
	{
		int counter = 0;
		for (int i = 0; i < arrLingth; i++)
		{
			if (CheckTheNumber_Odd_Or_Even(Array[i]) == enOddOrEven::Even)
				counter++;
		}
		return counter;
	}

	static int CountNumberOf_Positive_In_Array(int Array[], int arrLingth)
	{
		int counter = 0;
		for (int i = 0; i < arrLingth; i++)
		{
			if (Array[i] >= 0)
				counter++;
		}
		return counter;
	}

	static int CountNumberOf_Negative_In_Array(int Array[], int arrLingth)
	{
		int counter = 0;
		for (int i = 0; i < arrLingth; i++)
		{
			if (Array[i] < 0)
				counter++;
		}
		return counter;
	}

	static float MyABS(float Number)
	{
		if (Number < 0)
			return Number * -1;
		else
			return Number;
	}

	static float GetFractionPart(float Number)
	{

		return Number - int(Number);
	}

	static int MyRound(float Number)
	{

		float FractionPart = GetFractionPart(Number);
		if (abs(FractionPart) >= .5)
		{
			if (Number > 0)
				return ++Number;
			else
				return --Number;
		}
		else
			return Number;
	}

	static int Mysqrt(int Number)
	{
		return pow(Number, 0.5);
	}

	static int MyCeil(float Number)
	{
		if (Number > 0)
			return int(++Number);
		else
			return int(Number);
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","one","two","three","four","five","six","seven","eight","nine","ten",
			"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "hundred " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "million " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One billion " + NumberToText(Number % 1000000000);
		}
		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + "billion " + NumberToText(Number % 1000000000);
		}
	}




};

