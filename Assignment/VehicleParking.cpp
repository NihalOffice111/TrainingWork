#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;


class Vehicle
{
public:
    string vehicleName;
    string vehicleNumber;
    string vehicleType;
    time_t entry;
    time_t exit;
    double fees;

    Vehicle()
    {
        
    }
    Vehicle(string name, string number, string type)
    {
        vehicleName = name;
        vehicleNumber = number;
        vehicleType = type;
        entry = time(0);
        exit = entry;
    }

    void calculateFair()
    {
        double rate = 0;
        time_t nowtime = exit;
        double totaltime = difftime(nowtime, entry) / 3600;

        if (vehicleType == "Emergency")
        {
            rate = 25;
        }
        else
        {
            rate = 10;
        }

        fees = rate * totaltime;
       
    }

    friend ostream& operator<<(ostream& os, const Vehicle& vehicle) {
        os << "Vehicle Name: " << vehicle.vehicleName << ", ";
        os << "Number: " << vehicle.vehicleNumber << ", ";
        os << "Type: " << vehicle.vehicleType << ", ";
        os << "Entry Time: " << ctime(&vehicle.entry);
        return os;
    }
};

class VehicleCompare
{
public:
    bool operator()(const Vehicle &v1, const Vehicle &v2)
    {
        if (v1.vehicleType == "Emergency" && v2.vehicleType != "Emergency")
            return false;
        if (v1.vehicleType != "Emergency" && v2.vehicleType == "Emergency")
            return true;

        return v1.vehicleName > v2.vehicleName;
    }
};

class ParkingSystem
{
public:
    priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> EmergencyBay;
    priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> NormalBay;
    vector<stack<Vehicle>> parkinglots;
    double fair = 0;

    // Vehicle v1;
    void VehiclesInQueues(vector<Vehicle> v)
    {
        for (auto x : v)
        {
            // if (x.vehicleType == "Emergency" )
            // {
            //     if(Queue1.size() < 5){
            //         Queue1.push(x);
            //     }
            //     else if(Queue1.size() >= 5 && Queue2.size() < 8){
            //         Queue2.push(x);
            //     }
            // }
            // else if(x.vehicleType == "Car" || x.vehicleType == "Bike"){
            //     if(Queue1.size() < 5){
            //         Queue1.push(x);
            //     }
            //     else if(Queue1.size() >= 5 && Queue2.size() < 8){
            //         Queue2.push(x);
            //     }
            // }
            // else{
            //     cout<<"Error"<<endl;
            // }

            if (x.vehicleType == "Emergency")
            {
                EmergencyBay.push(x);
            }
            else if(x.vehicleType == "Car" || x.vehicleType == "Bike")
            {
                NormalBay.push(x);
            }
        }


        cout<<"Vehicles are in queue Now "<<endl;
      // displayVehiclesInQueue();
        VehiclesInParkingLots(EmergencyBay, NormalBay);
    }
    


    void VehiclesInParkingLots(priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> pq1, priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> pq2)
    {
        parkinglots.resize(5);  
            int randomtime = 1;
    
        

        for (int i = 0; i < 5; i++)
        {
            if (!pq1.empty())
            {
                for (int j = 0; j < 4 && !pq1.empty(); j++)
                {
                    Vehicle veh = pq1.top();
                    pq1.pop();
                    randomtime = randomtime * 1;
                   // this_thread::sleep_for(chrono::seconds(randomtime));
                    parkinglots[j].push(veh);
                }
            }
        }
        
        cout<<"Emergency bay is Empty "<<endl;
        int randomtime2 = 1;
        for (int i = 0; i < 5; i++)
        {
            if (!pq2.empty())
            {
                for (int j = 0; j < 4 && !pq2.empty(); j++)
                {
                    Vehicle veh = pq2.top();
                    pq2.pop();
                    randomtime2 = randomtime2 * 1;
                    //this_thread::sleep_for(chrono::seconds(randomtime2));
                    
                    parkinglots[j].push(veh);
                }
            }
        }
        cout<<"Normal Bay is Empty "<<endl;
        cout<<endl;
        
        cout<<"Vehicle Are in Parking lots : "<<endl;
        cout<<endl;
        display();
        VehicleLeavingParkingLots(parkinglots);
    }

    void VehicleLeavingParkingLots(vector<stack<Vehicle>> slots)
    {
        stack<Vehicle> VehicleDetailsAfterLeavingLot;
        for (auto &lot : slots)
        {
            stack<Vehicle> temp = lot;
            
            while (!temp.empty())
            {
                Vehicle v = temp.top();
                temp.pop();

                v.exit = time(0);
                
                v.calculateFair();
                fair = fair + v.fees;
                
                
                VehicleDetailsAfterLeavingLot.push(v);
                cout<<"Vehicles: "<<v.vehicleName<<endl;
                cout<<"Type: "<<v.vehicleType<<endl;
                cout<<"Number: "<<v.vehicleNumber<<endl;
                cout<<"fair: Rs."<<v.fees<<endl;


                
                cout<<endl;
            }
        }
        
        cout<<"Details of the Vehicles When They Leave the parking lots "<<endl;
        while(!VehicleDetailsAfterLeavingLot.empty()){
            cout<<VehicleDetailsAfterLeavingLot.top()<<endl;
        
            VehicleDetailsAfterLeavingLot.pop();
        }
        cout<<endl;
    }

    void populateQueues()
    {
        Vehicle v3("TVS", "MH67IU8765", "Bike");
        Vehicle v1("Ford", "MH21YU7322", "Emergency");
        Vehicle v2("Maruti", "MH44OP6754", "Car");
        Vehicle v4("Tata","MH76UI9876","Emergency");
        Vehicle v5("Fiat","TG45OU8833","Car");
        Vehicle v6("BMW","MH87JK2323","Bike");
        Vehicle v7("Police","JK32IO4323","Emergency");
        Vehicle v8("Honda","BH88JH0001","Car");
        Vehicle v9("Military","JU90MN9876","Emergency");
        

        vector<Vehicle> v = {v1,v2, v3,v4,v5,v6,v7,v8,v9};
        VehiclesInQueues(v);
    }

    void display(){
        for (int i = 0; i < parkinglots.size(); i++) {
            stack<Vehicle> tempStack = parkinglots[i]; 
            while (!tempStack.empty()) {
                cout << tempStack.top() <<endl; 
                tempStack.pop(); 
            }
            cout << endl;
        }
    }
};
int main()
{

    ParkingSystem ps;
    ps.populateQueues();
    
    
    

    return 0;
}































// #include <bits/stdc++.h>
// #include <thread>
// #include <chrono>
// using namespace std;

// class Vehicle
// {
// public:
//     string vehicleName;
//     string vehicleNumber;
//     string vehicleType;
//     time_t entry;
//     time_t exit;
//     double fees;

//     Vehicle() {}
    
//     Vehicle(string name, string number, string type)
//     {
//         vehicleName = name;
//         vehicleNumber = number;
//         vehicleType = type;
//         entry = time(0);
//         exit = entry;
//     }

//     void calculateFair()
//     {
//         double rate = 0;
//         time_t nowtime = exit;
//         double totaltime = difftime(nowtime, entry) / 3600;

//         if (vehicleType == "Emergency")
//         {
//             rate = 25;
//         }
//         else
//         {
//             rate = 10;
//         }

//         fees = rate * totaltime;
//     }

//     friend ostream& operator<<(ostream& os, const Vehicle& vehicle)
//     {
//         os << "Vehicle Name: " << vehicle.vehicleName << ", ";
//         os << "Number: " << vehicle.vehicleNumber << ", ";
//         os << "Type: " << vehicle.vehicleType << ", ";
//         os << "Entry Time: " << ctime(&vehicle.entry);
//         return os;
//     }
// };

// class VehicleCompare
// {
// public:
//     bool operator()(const Vehicle &v1, const Vehicle &v2)
//     {
//         if (v1.vehicleType == "Emergency" && v2.vehicleType != "Emergency")
//             return false;
//         if (v1.vehicleType != "Emergency" && v2.vehicleType == "Emergency")
//             return true;

//         return v1.vehicleName > v2.vehicleName;
//     }
// };

// class ParkingSystem
// {
// public:
//     priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> EmergencyBay;
//     priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> NormalBay;
//     vector<stack<Vehicle>> parkinglots;
//     stack<Vehicle> VehicleDetailsAfterLeavingLot;
//     double fair = 0;

//     vector<Vehicle> VehiclesInQueues(vector<Vehicle> v)
//     {
//         for (auto x : v)
//         {
//             if (x.vehicleType == "Emergency")
//             {
//                 EmergencyBay.push(x);
//             }
//             else if (x.vehicleType == "Car" || x.vehicleType == "Bike")
//             {
//                 NormalBay.push(x);
//             }
//         }
//         cout << "Vehicles are in queue Now " << endl;
//         return v;
//     }

//     void VehiclesInParkingLots(priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> pq1, priority_queue<Vehicle, vector<Vehicle>, VehicleCompare> pq2)
//     {
//         parkinglots.resize(5);  
//         int randomtime = 1;

//         for (int i = 0; i < 5; i++)
//         {
//             if (!pq1.empty())
//             {
//                 for (int j = 0; j < 3 && !pq1.empty(); j++)
//                 {
//                     Vehicle veh = pq1.top();
//                     pq1.pop();
//                     randomtime = randomtime * 1;
//                     this_thread::sleep_for(chrono::seconds(randomtime));
//                     parkinglots[j].push(veh);
//                 }
//             }
//         }

//         cout << "Emergency bay is Empty " << endl;
//         int randomtime2 = 1;
//         for (int i = 0; i < 5; i++)
//         {
//             if (!pq2.empty())
//             {
//                 for (int j = 0; j < 3 && !pq2.empty(); j++)
//                 {
//                     Vehicle veh = pq2.top();
//                     pq2.pop();
//                     randomtime2 = randomtime2 * 1;
//                     this_thread::sleep_for(chrono::seconds(randomtime2));
//                     parkinglots[j].push(veh);
//                 }
//             }
//         }
//         cout << "Normal Bay is Empty " << endl;
//         cout << endl;
//     }

//     stack<Vehicle> VehicleLeavingParkingLots(vector<stack<Vehicle>> slots)
//     {
        
        
//         for (auto &lot : slots)
//         {
//             stack<Vehicle> temp = lot;
            
//             while (!temp.empty())
//             {
//                 Vehicle v = temp.top();
//                 temp.pop();

//                 v.exit = time(0);
//                 v.calculateFair();
//                 fair = fair + v.fees;

//                 VehicleDetailsAfterLeavingLot.push(v);
//                 cout << "Vehicles: " << v.vehicleName << endl;
//                 cout << "Type: " << v.vehicleType << endl;
//                 cout << "Number: " << v.vehicleNumber << endl;
//                 cout << "Fair: Rs." << v.fees << endl;
//                 cout << endl;
//             }
//         }
        
        
//         return VehicleDetailsAfterLeavingLot;
//     }

//     vector<Vehicle> populateQueues()
//     {
//         Vehicle v3("TVS", "MH67IU8765", "Bike");
//         Vehicle v1("Ford", "MH21YU7322", "Emergency");
//         Vehicle v2("Maruti", "MH44OP6754", "Car");
//         Vehicle v4("Tata", "MH76UI9876", "Emergency");
//         Vehicle v5("Fiat", "TG45OU8833", "Car");
//         Vehicle v6("BMW", "MH87JK2323", "Bike");
//         Vehicle v7("Police", "JK32IO4323", "Emergency");
//         Vehicle v8("Honda", "BH88JH0001", "Car");
//         Vehicle v9("Military", "JU90MN9876", "Emergency");

//         vector<Vehicle> v = {v1, v2, v3, v4, v5, v6, v7, v8, v9};
//         return v;
//     }

//     void display()
//     {
//         for (int i = 0; i < parkinglots.size(); i++) 
//         {
//             stack<Vehicle> tempStack = parkinglots[i]; 

//             while (!tempStack.empty()) 
//             {
//                 cout << tempStack.top() << endl;
//                 tempStack.pop(); 
//             }

//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     ParkingSystem ps;

//     vector<Vehicle> vehicles = ps.populateQueues();

//     vehicles = ps.VehiclesInQueues(vehicles);

//     ps.VehiclesInParkingLots(ps.EmergencyBay, ps.NormalBay);

//     // cout<<totalFare<<endl;
//     // double totalFare1 = ps.VehicleLeavingParkingLots(ps.parkinglots);
//     // cout<<totalFare1<<endl;
    
//     stack<Vehicle> VehicleDetailsAfterLeavingLot = ps.VehicleLeavingParkingLots(ps.parkinglots);
//     char ch;
//     cout<<"Do you want to See the Depature Vehicles Details "<<endl;
//     cin>>ch;
    
//     if(ch == 'y' || ch == 'Y'){
//             cout << "Details of the Vehicles When They Leave the parking lots " << endl;
//         while (!VehicleDetailsAfterLeavingLot.empty())
//         {
//             cout << VehicleDetailsAfterLeavingLot.top() << endl;
//             VehicleDetailsAfterLeavingLot.pop();
//         }
//         cout << endl;
//     }
    


//     //ps.display();

//     return 0;
// }
