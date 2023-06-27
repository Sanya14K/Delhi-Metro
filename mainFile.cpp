#include <iostream>
#include<vector>
#include<map>


#define ll long long int
#define rep0(i, n) for (int i = 0; i < n; i++)

using namespace std;


const int V = 286;
string metro_lst[V];
int metro_no[V];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void metro_fare(float dis)
{
    cout << "              Expected Metro Fare (Weekdays except Sunday) would be    :      Rs. ";
    if (dis <= 2.0)
    { // expected metro fare for shortest route distance <= 2 km.
        cout << 10.0 << endl;
    }
    else if (dis > 2.0 && dis <= 5.0)
    {
        cout << 20.0 << endl;
    }
    else if (dis > 5.0 && dis <= 12.0)
    {
        cout << 30.0 << endl;
    }
    else if (dis > 12.0 && dis <= 21.0)
    {
        cout << 40.0 << endl;
    }
    else if (dis > 21.0 && dis <= 32.0)
    {
        cout << 50.0 << endl;
    }
    else if (dis > 32.0)
    {
        cout << 60.0 << endl;
    }
    else
    {
        cout << "Not Known" << endl;
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int minDistance(float dist[], bool sptSet[])
{
    float min = 1000.0;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printPath(int parent[], int j, int src, vector<int> &cnt)
{
    if (parent[j] == src || parent[j] <= 0)
    {
        if (parent[j] == src)
        {
            cnt.push_back(metro_no[j]);
            cout << "  -->>  " << metro_lst[metro_no[j]];
        }
        return;
    }
    printPath(parent, parent[j], src, cnt);
    cnt.push_back(metro_no[j]);
    cout << "  -->>  " << metro_lst[metro_no[j]];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printSolution(float dist[], int src, int parent[], int dest, vector<int> &cnt)
{
    cout << endl<< "              Distance between two stations    :     " << dist[dest] << " km " << endl;
    metro_fare(dist[dest]);
    cout << metro_lst[metro_no[src]];
    cnt.push_back(metro_no[src]);
    printPath(parent, dest, src, cnt);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dijkstra(float graph[][V], int src, int d, vector<int> &cnt)
{
    float dist[V];
    bool sptSet[V];
    int parent[V];
    rep0(i, V)
    {
        parent[0] = -1;
        dist[i] = 1000.0;
        sptSet[i] = false;
    }

    dist[src] = 0.0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    cout << endl<< "              ";
    printSolution(dist, src, parent, d, cnt);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string yellow_line[37] = {"Samaypur Badli", "Rohini Sector 18,19", "Haiderpur Badli Mor", "Jahangirpuri", "Adarsh Nagar", "Azadpur", "Model Town", "G.T.B. Nagar", "Vishwavidyalaya", "Vidhan Sabha", "Civil Lines", "Kashmere Gate", "Chandni Chowk", "Chawri Bazar", "New Delhi", "Rajiv Chowk", "Patel Chowk", "Central Secretariat", "Udyog Bhawan", "Lok Kalyan Marg", "Jorbagh", "INA", "AIIMS", "Green Park", "Hauz Khas", "Malviya Nagar", "Saket", "Qutub Minar", "Chhatarpur", "Sultanpur", "Ghitorni", "Arjan Garh", "Guru Dronacharya", "Sikandarpur", "MG Road", "IFFCO Chowk", "Huda City Centre"};
float yl[37] = {0.0, 0.8, 1.3, 1.3, 1.3, 1.5, 1.4, 1.4, 0.8, 1.0, 1.3, 1.1, 1.1, 1.0, 0.8, 1.1, 1.3, 0.9, 0.3, 1.6, 1.2, 1.3, 0.8, 1.0, 1.8, 1.7, 0.9, 1.7, 1.3, 1.6, 1.3, 2.7, 2.3, 1.0, 1.2, 1.1, 1.5};


string red_line[29] = {"Shaheed Sthal", "Hindon River", "Arthala", "Mohan Nagar", "Shyam park", "Major Mohit Sharma", "Raj Bagh", "Shaheed Nagar", "Dilshad Garden", "Jhil Mil", "Mansarovar Park", "Shahdara", "Welcome", "Seelampur", "Shastri Park", "Kashmere Gate", "Tis Hazari", "Pul Bangash", "Pratap Nagar", "Shastri Nagar", "Inderlok", "Kanhaiya Nagar", "Keshav Puram", "Netaji Subash Place", "Kohat Enclave", "Pitam Pura", "Rohini East", "Rohini West", "Rithala"};
float rl[29] = {0.0, 1.0, 1.5, 0.7, 1.3, 1.2, 1.2, 1.3, 1.2, 0.9, 1.1, 1.1, 1.2, 1.1, 1.6, 2.1, 1.2, 0.9, 0.8, 1.7, 1.2, 1.2, 0.7, 1.2, 1.2, 1, 0.8, 1.3, 1};


string blue_line[50] = {"Dwarka Sector 21", "Dwarka Sector 8", "Dwarka Sector 9", "Dwarka Sector 10", "Dwarka Sector 11", "Dwarka Sector 12", "Dwarka Sector 13", "Dwarka Sector 14", "Dwarka", "Dwarka Mor", "Nawada", "Uttam Nagar West", "Uttam Nagar East", "Janka Puri West", "Janak Puri East", "Tilak Nagar", "Subhash Nagar", "Tagore Garden", "Rajouri Garden", "Ramesh Nagar", "Moti Nagar", "Kirti Nagar", "Shadipur", "Patel Nagar", "Rajendra Place", "Karol Bagh", "Jhandelwalan", "R K Ashram Marg", "Rajiv Chowk", "Barakhamba", "Mandi House", "Pragati Maidan", "Indraprastha", "Yamuna Bank", "Akshardham", "Mayur Vihar Phase-1", "Mayur Vihar Extension", "New Ashok Nagar", "Noida Sector 15", "Noida Sector 16", "Noida Sector 18", "Botanical Garden", "Golf Course", "Noida City Center", "Noida Sector 34", "Noida Sector 52", "Noida Sector 61", "Noida Sector 59", "Noida Sector 62", "Noida Electronic City"};
float bl[50] = {0.0, 1.7, 1.0, 1.1, 1.0, 1.0, 0.9, 0.9, 1.5, 1.1, 1.2, 1.0, 1.0, 1.3, 1.0, 1.0, 0.9, 0.9, 1.1, 1.0, 1.2, 1.0, 0.7, 1.3, 0.9, 1.0, 1.2, 1.0, 1.2, 0.7, 1.0, 0.8, 0.8, 1.8, 1.3, 1.8, 1.2, 0.9, 1.0, 1.1, 1.1, 1.1, 1.2, 1.3, 0.9, 1.2, 1.2, 1.0, 1.2, 1.2};

string blue_line2[8] = {"Yamuna Bank", "Laxmi Nagar", "Nirman Vihar", "Preet Vihar", "Karkarduma", "Anand Vihar", "Kaushambi", "Vaishali"};
float bl2[8] = {0.0, 1.3, 1.1, 1.0, 1.2, 1.1, 0.8, 1.6};


string orange_line[6] = {"New Delhi", "Shivaji Stadium", "Dhaula Kuan", "Delhi Aero City", "IGI Airport", "Dwarka Sector 21"};
float ol[6] = {0.0, 1.9, 6.4, 6.2, 3.4, 2.9};


string green_line[21] = {"Inder Lok", "Ashok Park Main", "Punjabi Bagh", "Shivaji Park", "Madipur", "Paschim Vihar East", "Paschim Vihar West", "Peera Garhi", "Udyog Nagar", "Maharaja Surajmal Stadium", "Nangloi", "Nangloi Railway Station", "Rajdhani Park", "Mundka", "Mundka Industrial Area", "Ghevra Metro Station", "Tikri Kalan", "Tikri Border", "Pandit Shree Ram", "Bahdurgarh City", "Brig Hoshiar Singh"};
float gl[21] = {0.0, 1.4, 0.9, 1.6, 1.1, 0.7, 1.0, 0.9, 1.2, 0.7, 0.8, 0.9, 1.2, 1.3, 1.3, 2.1, 1.8, 1.3, 1.3, 1.5, 1.8};

string green_line2[3] = {"Ashok Park Main", "Satguru Ram Singh Marg", "Kirti Nagar"};
float gl2[3] = {0.0, 1.1, 1.0};


string rapid_line[11] = {"Sector 55-66", "Sector 54 Chowk", "Sector 53-54", "Sector 42-43", "DLF Phase 1", "Sikandarpur", "DLF Phase 2", "Vodaphone Belvedere Towers", "Indus Bank Cyber City", "Micromax Moulsari", "DLF Phase 3"};
float rapl[11] = {0.0, 1.1, 1.5, 1.3, 1.6, 1.1, 0.7, 0.7, 0.6, 0.6, 0.8};


string voilet_line[34] = {"Kashmere Gate", "Lal Quila", "Jama Masjid", "Delhi Gate", "ITO", "Mandi House", "Janpath", "Central Secretariat", "Khan Market", "Jawaharlal Nehru Stadium", "Jangpura", "Lajpat Nagar", "Moolchand", "Kailash Colony", "Nehru Place", "Kalkaji Mandir", "Govind Puri", "Okhla", "Jasola", "Sarita Vihar", "Mohan Estate", "Tughlakabad", "Badarpur", "Sarai", "NHPC Chowk", "Mewala Maharajpur", "Sector 28 Faridabad", "Badkal Mor", "Old Faridabad", "Neelam Chowk Ajronda", "Bata Chowk", "Escorts Mujesar", "Sant Surdas-Sihi", "Raja Nahar Singh"};
float vl[34] = {0.0, 1.5, 0.8, 1.4, 1.3, 0.8, 1.4, 1.3, 2.1, 1.4, 0.9, 1.5, 0.7, 1.3, 1.0, 0.8, 0.7, 1.1, 0.9, 1.2, 1.2, 1.9, 1.1, 2.5, 1.6, 0.9, 1.2, 1.7, 1.2, 1.6, 1.3, 1.8, 1.7, 1.7};


string magenta_line[25] = {"Janak Puri West", "Dabri Mor", "Dashrath Puri", "Palam", "Sadar Bazaar Cantonment", "Terminal 1 IGI Airport", "Shankar Vihar", "Vasant Vihar", "Munirka", "RK Puram", "IIT Delhi", "Hauz Khas", "Panchsheel Park", "Chirag Delhi", "Greater Kailash", "Nehru Enclave", "Kalkaji Mandir", "Okhla NSIC", "Sukhdev Vihar", "Jamia Millia Islamia", "Okhla Vihar", "Jasola Vihar Shaheen Bagh", "Kalindi Kunj", "Okhla Bird Sanctuary", "Botanical Garden"};
float ml[25] = {0.0, 2.0, 1.1, 1.5, 2.6, 1.7, 1.8, 2.1, 1.2, 1.4, 0.9, 1.2, 1.5, 0.9, 0.9, 1.3, 0.9, 0.8, 1.1, 1.2, 0.5, 1.8, 1.4, 1.6, 1.7};


string pink_line[38] = {"Majlis Park", "Azadpur", "Shalimar Bagh", "Netaji Subhash Place", "Shakurpur", "Punjabi Bagh West", "ESI Hospital", "Rajouri Garden", "Mayapuri", "Naraina Vihar", "Delhi Cantt", "Durgabai Deshmukh South Campus", "Sir M. Vishweshwaraiah Moti Bagh", "Bhikaji Cama Place", "Sarojini Nagar", "Dilli Haat INA", "South Extension", "Lajpat Nagar", "Vinobapuri", "Ashram", "Sarai Kale Khan Nizamuddin", "Mayur Vihar Phase-1", "Mayur Vihar Pocket I", "Trilokpuri Sanjay Lake", "Vinod Nagar East", "Mandawali - West Vinod Nagar", "IP Extension", "Anand Vihar", "Karkarduma", "Karkarduma Court", "Krishna Nagar", "East Azad Nagar", "Welcome", "Jaffrabad", "Maujpur-Babarpur", "Gokulpuri", "Johri Enclave", "Shiv Vihar"};
float pl[38] = {0.0, 2.1, 1.6, 1.4, 1.2, 1.4, 2.5, 1.1, 1.5, 1.5, 1.8, 3.6, 1.3, 1.6, 1.2, 1.1, 1.2, 1.6, 1.4, 1.2, 1.9, 3.6, 0.8, 1.3, 0.8, 0.6, 1.0, 1.6, 1.0, 1.1, 0.7, 1.0, 1.1, 1.2, 1.1, 1.3, 1.3, 0.9};


string aqua_line[21] = {"Noida Sector 51", "Noida Sector 50", "Noida Sector 76", "Noida Sector 101", "Noida Sector 81", "NSEZ Noida", "Noida Sector 83", "Noida Sector 137", "Noida Sector 142", "Noida Sector 143", "Noida Sector 144", "Noida Sector 145", "Noida Sector 146", "Noida Sector 147", "Noida Sector 148", "Knowledge Park II", "Pari Chowk Greater Noida", "Alpha 1 Greater Noida", "Delta 1 Greater Noida", "GNIDA Office", "Depot Greater Noida"};
float al[21] = {0.0, 1.3, 1.0, 1.1, 0.9, 2.0, 1.1, 1.5, 1.6, 1.0, 1.4, 1.2, 1.7, 1.5, 1.6, 2.5, 1.1, 0.9, 1.5, 1.3, 0.9};

// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤

string grey_line[4] = {"Dwarka", "Nangli", "Najafgarh", "Dhansa Bus Stand"};
float grl[4] = {0.0, 1.5, 2.4};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
print_response()
{
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t---                                                       METRO APP                                                       --- \t\t" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout<<endl;
    cout<<endl<<"              Press : "<<endl;
    cout<<endl;

    cout << "              1               :        For listing with their respective Delhi Metro Stations with their IDs " << endl;
    cout << "              2               :        For For finding shortest route" << endl;
    cout << "              3               :        For Ticketing and Token information" << endl;
    cout << "              Any other key   :        To Exit" << endl;

    cout << endl<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout <<endl<<endl<< "              Enter Your Response : ";

    // cout << "----------------------------------------------------------" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void print_ticket()
{
    cout << endl
         << endl;
    cout << "----------TOKEN---------" << endl;
    cout << "1. Only One way permitted" << endl;
    cout << "2. Validity One day" << endl;
    cout << "3. Refund with in 60 min" << endl;
    cout << "4. Exit within 170 min, penalty Rs 10 per hour, subject to maximum Rs 50" << endl;

    cout << endl
         << endl;
    cout << "----------TRAVEL CARD---------" << endl;
    cout << "1. First Time Rs 150 ( including Rs 50 refundable security" << endl;
    cout << "2. Next recharge Rs 200 to Rs 2000" << endl;
    cout << "3. Validity - 1 year after every recharge, max 10 years" << endl;
    cout << "4. Same station entry/exit Rs 10 charged with in 20 min" << endl;
    cout << endl
         << endl;

    cout << "----------BENIFITS OF DELHI METRO SMART CARD---------" << endl;
    cout << "1. It provides 10 pre cent discount on every ride." << endl;
    cout << "2. Off Peak hours - between 6am to 8am, 12pm to 5pm and 10 pm onwards - can avail a discount of 20 per cent." << endl;
    cout << "3. On Sundays and National Holidays - there is a discount of Rs. 10" << endl;
    cout << "4. You can buy card worth Rs 150 to Rs2000 at one time and return it anytime to get the balance amount back" << endl;
    cout << "5. Refundable Security deposit Rs50" << endl;
    cout << "6. Discount is not applicable if Entry/Exit is made from the same station" << endl;
    cout << endl
         << endl;

    cout << "----------TOURIST CARD---------" << endl;
    cout << "1. Specially for a single day travel" << endl;
    cout << "2. Purchase a card word Rs100 and travel whole day to any station on the Delhi Metro" << endl;
    cout << "3. 1 day Rs 200 (Rs 150 + Rs 50 refundable security)" << endl;
    cout << "4. 3 Days Rs 500 (Rs. 450 + Rs 50 refundable security)" << endl;
    cout << endl
         << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    map<string, int> metro;

    float graph[V][V];
    memset(graph, 0.0, sizeof(graph));
    int count = 0;

    // providing numbers to metro stations in yellow line 

    rep0(i, 37)
    {
        if (!metro[yellow_line[i]])
        {
            metro[yellow_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in red line  

    rep0(i, 29)
    {
        if (!metro[red_line[i]])
        {
            metro[red_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in blue line 

    rep0(i, 50)
    {
        if (!metro[blue_line[i]])
        {
            metro[blue_line[i]] = count;
            count++;
        }
    }


    rep0(i, 8)
    {
        if (!metro[blue_line2[i]])
        {   
            metro[blue_line2[i]] = count;
            count++;
        }
    }



    rep0(i, 6)
    {
        if (!metro[orange_line[i]])
        {
            metro[orange_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in green line  

   
    rep0(i, 21)
    {
        if (!metro[green_line[i]])
        {
            metro[green_line[i]] = count;
            count++;
        }
    }

    rep0(i, 3)
    {
        if (!metro[green_line2[i]])
        {
            metro[green_line2[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in rapid line 

    rep0(i, 11)
    {
        if (!metro[rapid_line[i]])
        {
            metro[rapid_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in violet line 

    rep0(i, 34)
    {
        if (!metro[voilet_line[i]])
        {
            metro[voilet_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in magenta line 

    rep0(i, 25)
    {
        if (!metro[magenta_line[i]])
        {
            metro[magenta_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in pink line 

    rep0(i, 38)
    {
        if (!metro[pink_line[i]])
        {
            metro[pink_line[i]] = count;
            count++;
        }
    }

    // providing numbers to metro stations in aqua line  

    rep0(i, 21)
    {
        if (!metro[aqua_line[i]])
        {
            metro[aqua_line[i]] = count;
            count++;
        }
    }


    // providing numbers to metro stations in grey line 

    rep0(i, 4)
    {
        if (!metro[grey_line[i]])
        {
            metro[grey_line[i]] = count;
            count++;
        }
    }


    /////////////////////////////////////////////////////////// connecting connecting connecting connecting ///////////////////////////////////////////////////////////////////////////////

    // connecting metro stations on yellow line  
    rep0(i, 36)
    {
        int u = metro[yellow_line[i]];
        int v = metro[yellow_line[i + 1]];
        graph[u][v] = yl[i + 1];
        graph[v][u] = yl[i + 1];
    }

    // connecting metro stations on red line  
    rep0(i, 28)
    {
        int u = metro[red_line[i]];
        int v = metro[red_line[i + 1]];
        graph[u][v] = rl[i + 1];
        graph[v][u] = rl[i + 1];
    }

    // connecting metro stations on blue line 
    rep0(i, 49)
    {
        int u = metro[blue_line[i]];
        int v = metro[blue_line[i + 1]];
        graph[u][v] = bl[i + 1];
        graph[v][u] = bl[i + 1];
    }
    rep0(i, 7)
    {
        int u = metro[blue_line2[i]];
        int v = metro[blue_line2[i + 1]];
        graph[u][v] = bl2[i + 1];
        graph[v][u] = bl2[i + 1];
    }

    // connecting metro stations on orange line 

    rep0(i, 5)
    {
        int u = metro[orange_line[i]];
        int v = metro[orange_line[i + 1]];
        graph[u][v] = ol[i + 1];
        graph[v][u] = ol[i + 1];
    }

    // connecting metro stations on green line 

    rep0(i, 20)
    {
        int u = metro[green_line[i]];
        int v = metro[green_line[i + 1]];
        graph[u][v] = gl[i + 1];
        graph[v][u] = gl[i + 1];
    }

    rep0(i, 2)
    {
        int u = metro[green_line[i]];
        int v = metro[green_line[i + 1]];
        graph[u][v] = gl2[i + 1];
        graph[v][u] = gl2[i + 1];
    }

    // connecting metro stations on rapid line 

    rep0(i, 10)
    {
        int u = metro[rapid_line[i]];
        int v = metro[rapid_line[i + 1]];
        graph[u][v] = rapl[i + 1];
        graph[v][u] = rapl[i + 1];
    }

    // connecting metro stations on violet line 

    rep0(i, 33)
    {
        int u = metro[voilet_line[i]];
        int v = metro[voilet_line[i + 1]];
        graph[u][v] = vl[i + 1];
        graph[v][u] = vl[i + 1];
    }

    // connecting metro stations on magenta line 

    rep0(i, 24)
    {
        int u = metro[magenta_line[i]];
        int v = metro[magenta_line[i + 1]];
        graph[u][v] = ml[i + 1];
        graph[v][u] = ml[i + 1];
    }

    // connecting metro stations on pink line 

    rep0(i, 37)
    {
        int u = metro[pink_line[i]];
        int v = metro[pink_line[i + 1]];
        graph[u][v] = pl[i + 1];
        graph[v][u] = pl[i + 1];
    }

    // connecting metro stations on aqua line 

    rep0(i, 20)
    {
        int u = metro[aqua_line[i]];
        int v = metro[aqua_line[i + 1]];
        graph[u][v] = al[i + 1];
        graph[v][u] = al[i + 1];
    }

    // connecting metro stations on grey line 
    rep0(i, 3)
    {
        int u = metro[grey_line[i]];
        int v = metro[grey_line[i + 1]];
        graph[u][v] = grl[i + 1];
        graph[v][u] = grl[i + 1];
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int k = 0;
    for (auto i : metro)
    {
        metro_lst[k] = i.first;
        metro_no[i.second] = k;
        k++;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
    int src;
    int dt;
    
    bool  Continue = true;

    while (Continue ){

        print_response();
        string response;
        cin >> response;
        cout << endl;

        if (response == "2")
        {
            vector<int> cnt;

            cout << "              Enter starting station ID :";
            cin >> src;
            cout << endl
                 << "              Enter ending station ID :";
            cin >> dt;

            cout << endl<< "              Starting Station    :    " << metro_lst[metro_no[src]];
            cout << endl<< "              Ending Station      :    " << metro_lst[metro_no[dt]] << endl;

            dijkstra(graph, int(src), int(dt), cnt);

            cout << "\n\n              Number of station in between these two staions are : " << cnt.size() << endl;
        }
        else if (response == "3")
        {
            print_ticket();
        }
        else if (response == "1")
        {

            cout<<endl;

            char ch='A';
            int cnt=-1;

            for (auto i : metro)
            { 
                
                string word = i.first;
                int size = word.length();
                int len = 50 - size;

                if(cnt == 4) cnt++;
                else if (word[0]-'A' > cnt){
                    cout << endl << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "              METRO STATIONS STARTING WITH LETTER ' " << word[0] << " '" << endl;
                    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cnt++;
                }

                word.append(len, ' ');
                
                cout <<"              "<<word;
                cout<< "->" << i.second << endl;
            }
            cout<<endl<<endl<<endl<<endl<<endl;
        }
        else
        {
            Continue=false;
        }
        
    }


    return 0;
}
