#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<element> map;
	string input = "abdc abdc bjau qifp abdc acbd";
	int firstindex = 0;
	for (int i = 0; i < input.length; i++) {
		if (input[i] == ' ') {
			string substring = input.substr(firstindex, i - firstindex + 1);
			put_unsorted(substring, map);
			firstindex = i + 1;
		}
	}
	element elem("abdc", 3);
	if (findInMap(elem, map) != map.end()) {
		erase(elem, map);
	}
	print(map);
}

struct element {
	element(string _str, int _val) : str(_str), val(_val) {}
	string str;
	int val;
};

void print(vector<element> m) {
	vector<int>::size_type sz = m.size();
	for (unsigned i = 0; i < sz; i++) {
		cout << m[i].str << "    " << m[i].val << endl;
	}
}
vector<element>::iterator findInMap(element e, vector<element> m) {
	vector<element>::iterator it;
	it = find(m.begin(), m.end(), e);
	if(it != m.end())
		return it;
	return m.end();
}

vector<element>::iterator put_unsorted(string word, vector<element> m) {
	vector<int>::size_type sz = m.size();
	for (unsigned i = 0; i < sz; i++) {
		if (m[i].str == word) {
			m[i].val++;
			element elem(word, m[i].val);
			return (find(m.begin(), m.end(), elem));
		}
	}
	element new_elem(word, 1);
	m.push_back(new_elem);

	return (find(m.begin(), m.end(), new_elem));
}

vector<element>::iterator put_sorted(string word, vector<element> m) {
	vector<int>::size_type sz = m.size();
	for (unsigned i = 0; i < sz; i++) {
		if (m[i].str == word) {
			m[i].val++;
			element elem(word, m[i].val);
			return (find(m.begin(), m.end(), elem));
		}
	}
	for (unsigned i = 0; i < sz; i++) {
		element new_elem(word, 1);
		string str1 = m[i].str;
		if (strcmp(word, str1) > 0) {
			m.emplace(new_elem);
			return (find(m.begin(), m.end(), new_elem));
		}
		
	}
}

void erase(element elem, vector<element> m) {
	vector<element>::iterator it = findInMap(elem, m);
	int index = distance(m.begin(), it);
	m.erase(m.begin() + index);
}

