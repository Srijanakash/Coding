/*
Given the array orders, which represents the orders that customers have done in a restaurant. 
More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, 
tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
Return the restaurant's “display table”. The “display table” is a table whose row entries 
denote how many of each food item each table ordered. The first column is the table number and the 
remaining columns correspond to each food item in alphabetical order. The first row should be a 
header whose first column is “Table”, followed by the names of the food items. Note that the 
customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.

Example 1:

Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],
["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],
["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 
Example 2:

Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],
["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
Explanation: 
For the table 1: Adam and Brianna order "Canadian Waffles".
For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
Example 3:

Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
*/

class Solution 
{
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) 
    {
        set<int>tables;
        set<string>foods;
        map<pair<int,string>,int>order;
        int l=orders.size();
        vector<vector<string>>res;
        for(int i=0;i<l;i++)
        {
            foods.insert(orders[i][2]);
            stringstream num(orders[i][1]);
            int x = 0; 
            num >> x; 
            tables.insert(x);
            order[make_pair(x,orders[i][2])]++;
        }
        vector<string>row0;
        row0.push_back("Table");
        for(auto i=foods.begin();i!=foods.end();i++)
            row0.push_back(*i);
        res.push_back(row0);
        for(auto i=tables.begin();i!=tables.end();i++)
        {
            vector<string>row;
            row.push_back(to_string(*i));
            for(auto j=foods.begin();j!=foods.end();j++)
            {
                int n=order[{*i,*j}];
                row.push_back(to_string(n));
            }
            res.push_back(row);
        }
        return res;
    }
};
