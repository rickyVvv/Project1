#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct Node //creating  a struct node
{
    char ch = ' '; //a char to hold our values of # and *
    Node *Right = nullptr; //this will make us go right
    Node *Left = nullptr; //left
    Node *Down = nullptr; //down 
    Node *Up = nullptr; //and up
};
void UP(Node *&Trav, bool Pen_status, int Length, bool Bold, bool &Bounds) //function so our code can move up
{
    Node *Anchor = Trav; //anchor this is a must
    if (Trav->Up == NULL) //boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
    {
        Bounds = false; //bounds are false
        return; //leave function
    }
    else
    {
        Bounds = true;// bounds are true
    }

    if (Pen_status == false) // pen is up
    {
        for (int i = 0; i < Length; i++)
        {
            if (Trav->Up == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false; //bounds are false
                Trav = Anchor; // this will reset our traverse node back to anchor to prevent memory leak
                return;
            }
            else
            {
                Bounds = true; // else bounds are true
            }
            Trav = Trav->Up; //this is so we can check to see all spots of up are indeed not NULL
        }
        Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
        for (int i = 0; i < Length; i++)
        {
            Trav = Trav->Up; // returns up by one from the current position
        }

        //should move this direction directly above if there are 50 line in this txt file
    }

    if (Pen_status == true) // pen is down
    {
        for (int i = 0; i < Length; i++)
        {
            
            if (Trav->Up == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false; //bounds are false
                Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
                return; //get out of function 
            }
            else
            {
                Bounds = true; //else bounds are true
            }
            Trav = Trav->Up; //go up
        }
        Trav = Anchor; //our pointer goes to anchor
        for (int i = 0; i < Length; i++)
        {

            Trav = Trav->Up; // we still want this to move up after pen status is true no?
            if (Bold == true) // bold is true
                Trav->ch = '#'; //our pointer char value equals bold
            else //checking for bold precedence
            {
                if (Trav->ch == '#')
                    Trav->ch = '#'; //bold precedence

                else // else print a '*' if the bold status that is used in main function is false
                {

                    Trav->ch = '*'; 
                }
            }
        }
    }
}
void Down(Node *&Trav, bool Pen_status, int Length, bool Bold, bool &Bounds) //function so our code can move down
{
    Node *Anchor = Trav;
    if (Trav->Down == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
    {
        Bounds = false; //bounds is false
        return;//leave function
    }
    else
    {
        Bounds = true;//bounds is true
    }

    if (Pen_status == false) // pen is up
    {
        for (int i = 0; i < Length; i++)
        {
            
            if (Trav->Down == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
                return; //leave function
            }
            else
            {
                Bounds = true; //bounds are true
            }
            Trav = Trav->Down; //going down
        }
        Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
        for (int i = 0; i < Length; i++)
        { //simple for loop to move where we need our function to move
            Trav = Trav->Down; // going down
        }

        //should move this direction directly down if there are 50 line in this txt file
    }

    if (Pen_status == true)
    { // when pen is down
        // we still want this to move up after pen status is true no?
        for (int i = 0; i < Length; i++)
        {
            if (Trav->Down == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
                return; //leave function
            }
            else
            {
                Bounds = true; // bounds are true
            }
            Trav = Trav->Down;
        }
        Trav = Anchor;// this will reset our traverse node back to anchor to prevent memory leak
        for (int i = 0; i < Length; i++) //simple for loop to move where we need our function to move
        {

            Trav = Trav->Down; // again should move directly down if there are 50 lines
            if (Bold == true)  // if the bold function is true or valid it should print this # out
                Trav->ch = '#'; //trav point will equal bold
            else
            {
                if (Trav->ch == '#') //checking for bold presedenece
                    Trav->ch = '#'; //bold presedence

                else // else print a '*' if the bold status that is used in main function is false
                {

                    Trav->ch = '*';
                }
            }
        }
    }
}
void LEFT(Node *&Trav, bool Pen_status, int Length, bool Bold, bool &Bounds) //function so our code can move left
{
    Node *Anchor = Trav;
    if (Trav->Left == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
    {
        Bounds = false;//bounds is false
        return; //leave function
    }
    else
    {
        Bounds = true; //bounds are true
    }

    if (Pen_status == false) // pen is up
    {
        for (int i = 0; i < Length; i++)
        {
            
            if (Trav->Left == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor; //pointer equal anchor
                return; //leave function
            }
            else
            {
                Bounds = true; //bounds are true
            }
            Trav = Trav->Left; //going to the left to check
        }
        Trav = Anchor;
        for (int i = 0; i < Length; i++) //simple for loop to move where we need our function to move
        {
            Trav = Trav->Left; // we've used -1 in all previous functions now we should know that -1 moves it to the left once
        }
    }

    if (Pen_status == true) // pen is down
    {
        for (int i = 0; i < Length; i++)
        {
            if (Trav->Left == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor; //trav is anchor
                return; //leave function
            }
            else
            {
                Bounds = true; //bounds are ture
            }
            Trav = Trav->Left; //pointer goes to the left
        }
        Trav = Anchor; //pointer goes to anchor
        for (int i = 0; i < Length; i++) //simple for loop to move where we need our function to move
        {

            Trav = Trav->Left; // again moves to the left once
            if (Bold == true)
                Trav->ch = '#'; //pointer at char is a #
            else
            {
                if (Trav->ch == '#')
                    Trav->ch = '#'; // bold presedence
                else // else print a '*' if the bold status that is used in main function is false
                {
                    
                    Trav->ch = '*';
                }
            }
        }
    }
}
void RIGHT(Node *&Trav, bool Pen_status, int Length, bool Bold, bool &Bounds) //function so our code can move right
{
    Node *Anchor = Trav;
    if (Trav->Right == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
    {
        Bounds = false;//bounds is false
        return; //leave function
    }
    else
    {
        Bounds = true; //bounds are true
    }

    if (Pen_status == false) // pen is up
    {
        for (int i = 0; i < Length; i++)
        {
            if (Trav->Right == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor; // trav is anchor
                return;
            }
            else
            {
                Bounds = true; //bounds are true
            }
            Trav = Trav->Right; //goes to the right
        }
        Trav = Anchor; //pointer goes to anchor
        for (int i = 0; i < Length; i++) //simple for loop to move where we need our function to move
        {
            Trav = Trav->Right; // in previous statements we went -1 to go back from our printed statement so to go one to the right we will make it a positive 1
        }
    }

    if (Pen_status == true) // when pen is down
    {
        for (int i = 0; i < Length; i++)
        {
            if (Trav->Right == NULL)//boundary check so if the next spot is NULL then we return false and treat this as an inavlid command
            {
                Bounds = false;//bounds is false
                Trav = Anchor; //pointer goes to anchor
                return; //leave function
            }
            else
            {
                Bounds = true; // bounds are true
            }
            Trav = Trav->Right; //goes to the right
        }
        Trav = Anchor; //pointer goes to anchor
        for (int i = 0; i < Length; i++) //simple for loop to move where we need our function to move
        {
            Trav = Trav->Right; // again a positive 1
            if (Bold == true)   //bold is true print a #
                Trav->ch = '#'; //bold
            else
            {
                if (Trav->ch == '#')
                    Trav->ch = '#'; // bold presedence
                else // else print a '*' if the bold status that is used in main function is false
                {
                    Trav->ch = '*'; 
                }
            }
        }
    }
}
void Print(ostream &file, Node *trav, int count)
{   

    if (count < 50) //checking for count for recursion
    {
        for (int i = 0; i < 50; i++) // printing file
        {
            if (i < 49)
            {
                file << trav->ch; //file print
                trav = trav->Right; //goes to right
            }
            else
            {
                file << trav->ch; //else a random thing thats usually not called
            }
        }
        if (count < 49)
        {
            file << endl; //count is < 49 then we cout a endl 
        }
        for (int j = 0; j < 49; j++)
        {

            trav = trav->Left; //now we go back
        }
        count++; //increment
        Print(file, trav->Down, count); //calling recursion but when we do we go down one :)
    }
}
void Delete(Node *&Trav)
{
    Node *head = Trav; //first head
    Node *head1 = Trav; //second
    Node *head2 = Trav; //third
    for (int i = 0; i < 50; i++)
    {
        head2 = head1->Down; //going down
        for (int j = 0; j < 50; j++)
        {
            head = head1->Right; //deleting everything 50X to the right
            delete head1; //delete head1
            head1 = head; //head 1 = head and head 1 is deleted
        }
        delete head1; // deleting head 1 again
        head1 = head2; //making it equal head 2
    }
}
int main()
{
    ofstream fn("paint.txt", ios::out); //paint txt

    Node *head = new Node; // declaring variables
    Node *head1 = head;
    Node *head2 = head;
    Node *node = head;
    Node *temp = head;
    Node *temp1 = head;
    Node *anchor = head;

    for (int i = 0; i < 50; i++) //for loop to link
    {

        if (i == 0) //while i = 0
        {
            for (int j = 0; j < 49; j++) //this is literally for our first row only
            {
                temp = node; //temp = node
                node = new Node; //making a new node
                node->Left = temp; //tying left with node and temp
                temp->Right = node; //now temp right = node tying yhem together
            }
        }
        else // else we tie everything
        {
            temp1 = anchor; //going to anchor
            anchor->Down = new Node;//anchor equals new node
            node = anchor->Down; //node = anchor down
            anchor = node; //tying down with anchor
            node->Up = temp1; //tying up with temp1
            for (int k = 0; k < 49; k++)
            {
                temp = node; //temp = node while node is connected with up and down
                temp1 = temp1->Right; //now tying right and left
                node = new Node; //node is a new node
                node->Left = temp; //node left goes to temp
                temp->Right = node; //temp right goes to node
                node->Up = temp1; //node up goes to temp 1
                temp1->Down = node; //and node down foes to node so everything with node is succesfully connected
            }
        }
    }
    int Length; //declaring variables
    bool Pen_status;
    bool Bold_status;
    bool CheckBounds = true;
    string x, y;
    cin >> y; //user input for file command
    ifstream commands(y); //file commands
    while (commands.fail()) //check to see if file is valid
    {
        cout << "Wrong File";
        return 1;
    }
    while (!commands.eof())//while commands does not equal end of file
    {
        //RESETING ALL VALUES WITHIN MY ARRAY
        x = "aaaaaaaaaaaaaa";
        x[0] = 'a';
        x[1] = 'a';
        x[2] = 'a';
        x[3] = 'a';
        x[4] = 'a';
        x[5] = 'a';
        x[7] = 'a';
        x[8] = 'a';
        x[9] = 'a';
        CheckBounds = true;
        //RESETING ALL VALUES WITHING MY ARRAY
        while (getline(commands, x))
        {
            if (x.size() < 5) // if commands is less than 5 break out and get new line
                break;
            if (x.size() > 10) //if commands is greater than 10 break out and get a new line
                break;
            if (x[0] != '1' && x[0] != '2') // if the first thing being inputed is NOT a 1 or 2 break out and get the new line
                break;
            if (x[1] != ',') //if the second thing is NOT a comma break out and get new line
                break;
            if (x[2] != 'N' && x[2] != 'S' && x[2] != 'E' && x[2] != 'W') //if the third thing is NOT a direction break out and get new line
                break;
            if (x[0] == '1' && x[6] == 'B') //if pen is up and bold is being called break out and get new line
                break;
            if (x[0] == '1' && x[7] == 'B') //theres two instance B can be called in the 6th and 7th position
                break;
            if (x[3] != ',') //if the 4th input isn't a comma break out
                break;
            if (x[9] != 'P' && x[10] == '\0') //if the last command is called and it doesn't end break out and get a new line
                break;
            if (x[5] == ',' && x[6] != 'B' && x[6] != 'P') // after the 6th equals a comma and the next commands is NOT a bold or print break out and get new line
                break;
            if (x[6] == ',' && x[7] != 'B' && x[7] != 'P') // after the 7th equals a comma and the next commands is NOT a bold or print break out and get new line
                break;
            if (x[7] == ',' && x[8] != 'P') // after the 8th equals a comma and the next commands is NOT a print break out and get new line
                break;
            if (x[8] == ',' && x[9] != 'P') // after the 9th equals a comma and the next commands is NOT a print break out and get new line
                break;
            if (x[6] == 'P' && x[7] == 'P' && x[8] == 'P' && x[9] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[6] == 'P' && x[7] == 'P' && x[8] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[6] == 'P' && x[7] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[6] == 'P' && x[8] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[6] == 'P' && x[9] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[7] == 'P' && x[8] == 'P' && x[9] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[7] == 'P' && x[8] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[7] == 'P' && x[9] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[8] == 'P' && x[9] == 'P') //CHECKING FOR REPEATED P's
                break;
            if (x[6] == 'B' && x[7] == 'B') //CHECKING FOR REPEATED B's
                break;
            if (x[4] != '1' && x[4] != '2' && x[4] != '3' && x[4] != '4' && x[4] != '5' && x[4] != '6' && x[4] != '7' && x[4] != '8' && x[4] != '9' && x[4] != '0') // 4th command has to be a integer
                break;
            if (x[6] == '1' || x[6] == '2' || x[6] == '3' || x[6] == '4' || x[6] == '5' || x[6] == '6' || x[6] == '7' || x[6] == '8' || x[6] == '9' || x[6] == '0') //6th command cannot equal a integer
                break;
            if (x[0] == '1') // pen is up
                Pen_status = false;
            if (x[0] == '2') //pen is down
                Pen_status = true;
            if (x[5] == ',') // if the 6th command is a comma that indicated that there was only one intger
            {
                Length = (x[4] - '0'); //converting a char to a integer
            }

            if (x[5] != ',' && x[5] != '\n')
            {                                                // if the 6th command does not equal a comma then we know that we got ourselves a double intger
                Length = (10 * (x[4] - '0') + (x[5] - '0')); // converting a char to a integer
            }

            if (x[6] == 'B' || x[7] == 'B') //two possible spots where B can be called
                Bold_status = true;         //making sure that B is true
            else                            //else bold is false
            {
                Bold_status = false;
            }
            if (x[5] == '\0')
            {                          //This is the security of my code sometimes there is no comma in the 5th spot and instead theres a null char so we took advantage of that
                Length = (x[4] - '0'); // converting a char to a integer
            }
            if (x[2] == 'N')
            {
                UP(head, Pen_status, Length, Bold_status, CheckBounds); //if x at 2 equals N we do UP
                if (CheckBounds == false) //checking for bounds as invalid input
                {
                    break;
                }
            }
            if (x[2] == 'S')
            {
                Down(head, Pen_status, Length, Bold_status, CheckBounds);//if x at 2 equals S we do Down
                if (CheckBounds == false)//checking for bounds as invalid input
                {
                    break;
                }
            }
            if (x[2] == 'E')
            {
                RIGHT(head, Pen_status, Length, Bold_status, CheckBounds);//if x at 2 equals E we do Right
                if (CheckBounds == false)//checking for bounds as invalid input
                {
                    break;
                }
            }
            if (x[2] == 'W')
            {
                LEFT(head, Pen_status, Length, Bold_status, CheckBounds);//if x at 2 equals W we do Left
                if (CheckBounds == false)//checking for bounds as invalid input
                {
                    break;
                }
            }
            if (x[8] == 'P' || x[6] == 'P' || x[7] == 'P' || x[9] == 'P') //checking for P's at the end so we can print
            {
                head2 = head;//temp head which equals value of head
                head = head1; //head goes to anchor
                Print(cout, head, 0); //passing head from positing 1X1 in the grid
                cout << endl; //i guess a necessary endl
                head = head2; //head now equals our old value again
            }
            break; //breaks out of the second while loop only to go back to the first to repeat the process
        }
    }
    head = head1; //head 1 is our anchor in this instance
    Print(fn, head, 0); //prints head
    head = head1; //go back to anchor just in case
    Delete(head); //delete head
    fn.close(); //close file
    commands.close(); //close file
    return 0; //return value
}
