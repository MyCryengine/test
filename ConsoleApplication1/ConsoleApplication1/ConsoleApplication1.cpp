// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> strMap;
	for (auto elem : completion)
	{
		if (strMap.end() == strMap.find(elem))
			strMap.insert(make_pair(elem, 1));
		else
			strMap[elem]++;
	}

	for (auto elem : participant)
	{
		if (strMap.end() == strMap.find(elem))
		{
			answer = elem;
			break;
		}
		else
		{
			strMap[elem]--;
			if (strMap[elem] < 0)
			{
				answer = elem;
				break;
			}
		}
	}
	return answer;
}



bool solution3(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		for (int k = i + 1; k < phone_book.size(); k++)
		{
			if (phone_book[i] == phone_book[k].substr(0, phone_book[i].size()))
			{
				answer = false;
				break;
			}
		}

	}

	return answer;
}


int solution5(vector<vector<string>> clothes) 
{
// 	map<string, int> m; //옷의 종류를 key 해당 종류의 수를 value로 하는 map함수
// 	vector<string> v; //옷의 종류를 저장해놓을 벡터함수
// 	for (int i = 0; i < clothes.size(); i++)
// 	{
// 		if (m[clothes[i][1]] == 0) 
// 		{ //처음 나오는 옷의 종류라면
// 			m[clothes[i][1]] = 1;
// 			v.push_back(clothes[i][1]);
// 		}
// 		else
// 		{
// 			m[clothes[i][1]]++;
// 		}
// 	}
// 	int result = 1;
// 	for (int i = 0; i < v.size(); i++)
// 	{
// 		result *= (m[v[i]] + 1);
// 	}
// 	return result - 1;

	int answer = 1;
	map<string, vector<string>> mCloth;
	for (auto elem : clothes)
	{
		mCloth[elem.at(1)].push_back(elem.at(0));
	}
	for (auto elem : mCloth)
	{
		answer *= elem.second.size() + 1;
	}
	answer--;
	return answer;
}



int main()
{
	vector<string> partici = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	//vector<string> com = { "119", "97674223", "1195524421"}; // 0
	vector<string> com = { "12", "88","123","567","1235" }; // 0
	vector<string> com1 = { "123","456","789" }; // 1
	vector<string> com2 = { "12","123","1235","567","88" }; // 0 
	vector<string> com3 = { "12", "88", "123", "567", "1235" }; //0
	//string str = solution1(partici, completion);
// 	bool b;
// 	b = solution3(com);
// 	std::cout << b << endl;
// 
// 	b = solution3(com1);
// 	std::cout << b << endl;
// 
// 	b = solution3(com2);
// 	std::cout << b << endl;
// 
// 	b = solution3(com3);
// 	std::cout << b << endl;

	vector<vector<string> > arr({

	vector<string>({ "yellowhat", "headgear" }),

	vector<string>({ "bluesunglasses", "eyewear" }),

	vector<string>({ "green_turban", "headgear" }),

		});

	solution5(arr);

	// 브런치
	// branch
	// main 1

	return 0;    


