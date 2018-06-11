#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char alphabet[5][5] = {
{ 'a', 'b', 'c', 'd', 'e' },
{ 'f', 'g', 'h', 'i', 'k' },
{ 'l', 'm', 'n', 'o', 'p' },
{ 'q', 'r', 's', 't', 'u' },
{ 'v', ' ', 'x', 'y', 'z' } };

string encrypt(const string & message)
{
   string res = "";
   vector<pair<int, int>> coords;
   int n = message.length();
   for(int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 5; k++)
				if (alphabet[j][k] == message[i])
					coords.push_back(make_pair(j, k));
	n = coords.size();
	string newCoords;
	for(int  i = 0; i < n; i++)
		newCoords.append(to_string(coords[i].first)).append(to_string(coords[i].second));
	newCoords.push_back(newCoords[0]);
	newCoords = newCoords.substr(1);
	for(int i = 0; i < n; i++)
	{
		coords[i] = make_pair(newCoords[i * 2] - '0', newCoords[i * 2 + 1] - '0');
	}
	for(int i = 0; i < n; i++){
		res.push_back(alphabet[coords[i].first][coords[i].second]);
	}
	return res;
}
string decrypt(const string & crypted_message)
{
	string res = "";
   vector<pair<int, int>> coords;
   int n = crypted_message.length();
   for(int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 5; k++)
				if (alphabet[j][k] == crypted_message[i])
					coords.push_back(make_pair(j, k));
	string newCoords;
	for(int  i = 0; i < n; i++)
		newCoords.append(to_string(coords[i].first)).append(to_string(coords[i].second));
	newCoords.insert(newCoords.begin(), newCoords[newCoords.length() - 1]);

	newCoords.pop_back();
	for(int i = 0; i < n; i++)
	{
		coords[i] = make_pair(newCoords[i * 2] - '0', newCoords[i * 2 + 1] - '0');
	}
	for(int i = 0; i < n; i++){
		res.push_back(alphabet[coords[i].first][coords[i].second]);
	}
	return res;

}
int main()
{
	cout << "Take a message\n";
	string s;
	getline(cin, s);
	int n = s.length();
	for(int i = 0; i < n; i++)
		if (s[i] == 'j')
			s[i] = 'i'; else
		if (s[i] == 'w')
			s[i] = 'v';
	string encrypted = encrypt(s);
	cout << "encrypted message is\n" << encrypted << endl;
	string decrypted = decrypt(encrypted);
	cout << "decrypted message is\n" << decrypted;
	return 0;
}
