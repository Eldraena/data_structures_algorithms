#include <iostream>
#include <vector>
using namespace std;

int N;		//the number of test cases
int B;		//number system
string S;	//first integer
string D;	//second integer

vector<int> vtS, vtD, vtRes;
vector<string> vtResConvert;
int isSNeg, isDNeg;
string ans;

void InputData()
{
	cin >> B >> S >> D;
	isSNeg = 1, isDNeg = 1;
	vtS.clear(), vtD.clear(), vtRes.clear(), vtResConvert.clear();
	if (S[0] == '-')
	{
		S = S.substr(1, S.size() - 1);
		isSNeg = -1;
	}
	if (D[0] == '-')
	{
		D = D.substr(1, D.size() - 1);
		isDNeg = -1;
	}

	for (int i = 0; i < S.size(); i++)
	{
		int temp = (S[i] >= 'A') ? S[i] - 55 : S[i] - 48;
		vtS.push_back(temp);
	}
	for (int i = 0; i < D.size(); i++)
	{
		int temp = (D[i] >= 'A') ? D[i] - 55 : D[i] - 48;
		vtD.push_back(temp);
	}
}

int convert2dec(string str_num)
{
	int res = 0;
	for (int i = 0; i < str_num.length(); i++)
	{
		int temp = (str_num[i] >= 'A') ? str_num[i] - 55 : str_num[i] - 48;
		res = res * B + temp;
	}
	return res;
}

string convert2base(int src)
{
	if (src == 0) return "0";
	string res = "";
	while (src > 0)
	{
		int temp = src % B;
		char cTemp = (temp >= 10) ? temp + 55 : temp + 48;
		res = cTemp + res;
		src = src / B;
	}
	return res;
}

void multiply()
{
	if ((S[0] == '0' && S.length() == 1) || (D[0] == '0' && D.length() == 1))
	{
		ans = "0";
		return;
	}

	for (int i = 0; i < vtS.size() + vtD.size() - 1; i++)
		vtRes.push_back(0);
	for (int i = 0; i < vtD.size(); i++)
	{
		for (int j = 0; j < vtS.size(); j++)
			vtRes[i + j] += vtD[i] * vtS[j];
	}
	for (int i = 0; i < vtRes.size(); i++)
		vtResConvert.push_back(convert2base(vtRes.at(i)));

	string temp = "0";
	for (int i = vtResConvert.size() - 1; i >= 0; i--)
	{
		string s = convert2base(vtRes[i] + convert2dec(temp));
		temp = s.substr(0, s.size() - 1);
		vtResConvert[i] = s[s.size() - 1];
	}
	vtResConvert[0] = temp + vtResConvert[0];
	(isSNeg * isDNeg > 0) ? ans = "" : ans = "-";
	for (int i = 0; i < vtResConvert.size(); i++)
		ans += vtResConvert[i];
}

int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		InputData();
		multiply();
		cout << ans << endl;
	}
	return 0;
}