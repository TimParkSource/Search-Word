#include "WordList.h"

WordList::WordList(const string & wrd, SinglyLinkedList<int> Line) 
{
	string copy = wrd;
	convertToLowerCase(copy);
	Word = copy;
	LineNumList = Line;
}
/////////////////////////////////////////////
void WordList::convertToLowerCase(string & text)
{
	string temp = "";

	for (size_t i = 0; i < text.length(); i++)
	{
			temp+=(tolower(text[i])); 
	}

	text = temp;
}
/////////////////////////////////////////////////////////
const SinglyLinkedList<int> WordList::getList()
{
	return LineNumList; 
}
string WordList::getWord()
{
	return Word;
}
void WordList::setList(SinglyLinkedList<int> L)  // hopefully this works
{
	LineNumList = L;
}
void WordList::setWord(string W)
{
	Word = W;
}
