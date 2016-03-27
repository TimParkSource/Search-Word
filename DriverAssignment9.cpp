#include "WordList.h"
using namespace std;

int main()  
{
	
	string inPutFileName;
	cout<<"Enter full path to input file: ";
	getline(cin, inPutFileName);

	ifstream in;
	in.open(inPutFileName);

	if(!in)            // don't need this if
	{
		cout<<"Failed to open input file."<<endl;
		exit(0);
	}

	string outputFileName;
	cout<<"Enter full path to output file name: ";
	getline(cin, outputFileName);
	ofstream out;
	out.open(outputFileName);

	if (!out)		   // don't need this if
	{
		cout<<"Failed to open output file."<<endl;
		exit(1);
	}
	
	BinarySearchTree<WordList> BST; // create the binary search tree in the beginning, don't put wordlist on top...
	
	int lineCounter = 1;

	while (in.peek() != EOF)  // 
	{
		string line;
		getline(in, line);
		for (int i = 0; i < line.length(); i++)  // good parse
		{
			if(!isalpha(line[i]))
			{
				line[i] = ' ';
			}
		}
		istringstream is(line);
		string temp;

		while(is.peek() != EOF)
		{
			is>>temp;
			WordList WL;
			WL.convertToLowerCase(temp);
			if (temp.length()>1)
			{
				//cout << temp << "()" << endl;  // change this later
				SinglyLinkedList<int> SL = WL.getList();
				WL.setWord(temp);

				if(!BST.contains(WL))
				{
					SL.addRear(lineCounter);
					WL.setList(SL);
					BST.add(WL);
				}
				else
				{
					SearchTreeNode<WordList> *STN; // must use pointer
					STN = BST.get(WL);
					SinglyLinkedList<int> Copy;
					Copy = STN->contents.getList();
					Copy.addRear(lineCounter);
					STN->contents.setList(Copy);
				}
			}
		}	
		
		lineCounter++;
	}

	BST.printInorder(cout);
	BST.printInorder(out);

	bool done = false;
	while(!done)
	{
		cout << "Enter a string to search: ";
		string term;
		cin >> term;
		WordList WL2;
		WL2.convertToLowerCase(term);
		SinglyLinkedList<int> SL = WL2.getList();
		WL2.setWord(term);
		SearchTreeNode<WordList> *STN;
		STN = BST.get(WL2);
		SinglyLinkedList<int> Copy;
		Copy = STN->contents.getList();
		cout << Copy << endl;
		
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
		cout<<endl;
	}

	system("pause");
	return 0;
}
