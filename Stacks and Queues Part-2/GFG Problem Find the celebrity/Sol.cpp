#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < M.size(); i++)
    {
        st.push(i);
    }

    while (st.size() >= 2)
    {
        int person1 = st.top();
        st.pop();
        int person2 = st.top();
        st.pop();
        // check potential cel b/w two persons
        // if person1 knows person2 then person2 may be a cel
        // if person1 does not know person2 then person1 may be cel
        if (M[person1][person2] == 1)
        {
            st.push(person2);
        }
        else
        {
            st.push(person1);
        }
    }
    // extract the potenstial cel
    int pot_cel = st.top();
    st.pop();

    for (int i = 0; i < M.size(); i++)
    {
        // if potential cel knows a person or person does not know pot_cel then there is no celebrity
        if (pot_cel != i)
        {
            if (M[pot_cel][i] == 1 || M[i][pot_cel] == 0)
            {
                return -1;
            }
        }
    }
    // return potenstial celebrity
    return pot_cel;
}