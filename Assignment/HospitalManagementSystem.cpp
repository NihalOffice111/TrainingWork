
#include <bits/stdc++.h>
using namespace std;

class Patient
{
public:
    int patientId;
    string patientName;

    Patient() {}

    Patient(int id, string name)
    {
        this->patientId = id;
        this->patientName = name;
    }
};

class Node1
{
public:
    Patient patient;
    Node1 *pleft;
    Node1 *pright;
    bool isThreaded = false;

    Node1(Patient patient)
    {
        this->patient = patient;
        pleft = nullptr;
        pright = nullptr;
    }
};

class Department
{
public:
    int deptid;
    string departmentName;

    Department() {}

    Department(int id, string name)
    {
        this->deptid = id;
        this->departmentName = name;
    }
};

class Node
{
public:
    Department dept;
    Node1 *pat;
    Node *dleft;
    Node *dright;

    Node(Department dept)
    {
        this->dept = dept;
        this->pat = nullptr;
        dleft = nullptr;
        dright = nullptr;
    }
};

class HospitalManagementSystem
{
public:
    Node *droot;

    HospitalManagementSystem()
    {
        droot = nullptr;
    }

    void Insertion(Department dept, Patient pat)
    {
        Node *dnewnode = new Node(dept);
        if (droot == nullptr)
        {
            droot = dnewnode;
        }
        else
        {
            Node *dtemp = droot;
            while (true)
            {
                if (dnewnode->dept.deptid < dtemp->dept.deptid)
                {
                    if (dtemp->dleft != nullptr)
                    {
                        dtemp = dtemp->dleft;
                    }
                    else
                    {
                        dtemp->dleft = dnewnode;
                        break;
                    }
                }
                else if (dnewnode->dept.deptid > dtemp->dept.deptid)
                {
                    if (dtemp->dright != nullptr)
                    {
                        dtemp = dtemp->dright;
                    }
                    else
                    {
                        dtemp->dright = dnewnode;
                        break;
                    }
                }
            }
        }
        dnewnode->pat = InsertionOfPatient(dnewnode->pat, pat);
    }

    Node1 *InsertionOfPatient(Node1 *proot, Patient pat)
    {
        Node1 *newnode = new Node1(pat);
        if (!proot)
        {
            return newnode;
        }
        Node1 *curr = proot;
        Node1 *ptemp = nullptr;
        while (curr != nullptr)
        {
            ptemp = curr;
            if (curr->patient.patientId > pat.patientId)
            {
                if (curr->pleft == nullptr)
                {
                    break;
                }
                else
                {
                    curr = curr->pleft;
                }
            }
            else
            {
                if (curr->pright == nullptr || curr->isThreaded)
                {
                    break;
                }
                else
                {
                    curr = curr->pright;
                }
            }
        }
        if (ptemp->patient.patientId > pat.patientId)
        {
            ptemp->pleft = newnode;
            newnode->pright = ptemp;
            newnode->isThreaded = true;
        }
        else
        {
            if (ptemp->isThreaded)
            {
                newnode->pright = ptemp->pright;
                ptemp->isThreaded = false;
            }
            ptemp->pright = newnode;
            newnode->isThreaded = true;
        }
        return proot;
    }

    Node *searchDepartment(Node *root, int deptid)
    {
        if (root == nullptr || root->dept.deptid == deptid)
        {
            return root;
        }

        if (deptid < root->dept.deptid)
        {
            return searchDepartment(root->dleft, deptid);
        }
        else
        {
            return searchDepartment(root->dright, deptid);
        }
    }

    void InorderPatients(Node1 *root)
    {
        if (root == nullptr)
        {
            cout << "No Patients" << endl;
            return;
        }

        Node1 *curr = root;
        while (curr != nullptr)
        {
            while (curr->pleft != nullptr)
            {
                curr = curr->pleft;
            }
            cout << "Patient ID: " << curr->patient.patientId << ", Name: " << curr->patient.patientName << endl;
            while (curr->isThreaded)
            {
                curr = curr->pright;
                cout << "Patient ID: " << curr->patient.patientId << ", Name: " << curr->patient.patientName << endl;
            }
            curr = curr->pright;
        }
    }

    void dichargePatient(int dept, int patt)
    {
        Node *temp = searchDepartment(droot, dept);
        if (temp != nullptr)
        {
            temp->pat = dichargePatientFromHospital(temp->pat, patt);
            cout << "Patient with ID " << patt << " has gotten Discharge " << endl;
        }
        else
        {
            cout << "Department with ID " << dept << "Not Found " << endl;
        }
    }

    Node1 *dichargePatientFromHospital(Node1 *pati, int patt)
    {
        if (pati == NULL)
        {
            return pati;
        }
        if (patt < pati->patient.patientId)
        {
            pati->pleft = dichargePatientFromHospital(pati->pleft, patt);
        }
        else if (patt > pati->patient.patientId)
        {
            pati->pright = dichargePatientFromHospital(pati->pright, patt);
        }
        else
        {
            if (pati->pleft == NULL || pati->pright == NULL)
            {
                Node1 *temp2 = pati;
                delete temp2;
                return nullptr;
            }
            else if (pati->pleft == NULL)
            {
                Node1 *temp = pati->pright;
                delete pati;
                return temp;
            }
            else if (pati->pright == NULL || pati->isThreaded)
            {
                Node1 *temp = pati->pleft;
                delete pati;
                return temp;
            }
            else
            {
                Node1 *temp = pati->pright;
                while (temp != nullptr && temp->pleft != nullptr)
                {
                    temp = temp->pleft;
                }
                pati->patient = temp->patient;
                pati->pright = dichargePatientFromHospital(pati->pright, temp->patient.patientId);
            }
        }
        return pati;
    }

    void displayDepartments(Node *root)
    {
        if (root == nullptr)
            return;

        cout << "Department: " << root->dept.departmentName << " (ID: " << root->dept.deptid << ")\n";
        cout << "Patients in Department: \n";
        InorderPatients(root->pat);
        cout << endl;

        displayDepartments(root->dleft);
        displayDepartments(root->dright);
    }
};

int main()
{
    HospitalManagementSystem hms;
    int dept;
    string deptname;
    int patid;
    string patname;
    int ch;
    char choice;
    Patient p1;
    Department *d1;

    cout << "1. ADD DEPARTMENT" << endl;
    cout << "2. DISCHARGE PATIENT FROM SPECIFIC DEPARTMENT" << endl;
    cout << "3. SHOW DEPARTMENT WITH PATIENTS" << endl;

    do
    {
        cout << "Enter the Choice from the Main Menu: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Department Id: ";
            cin >> dept;
            cout << "Enter the Department name: ";
            cin >> deptname;
            d1 = new Department(dept, deptname);
            cout << "Enter the Patient ID: ";
            cin >> patid;
            cout << "Enter the Patient name: ";
            cin >> patname;
            p1 = Patient(patid, patname);
            hms.Insertion(*d1, p1);

            char ispat;
            int n;
            cout << "Do you want to Add More Patients to this Department (Y/N): ";
            cin >> ispat;
            if (ispat == 'Y' || ispat == 'y')
            {
                cout << "How many more patients do you want to add? ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Enter the Patient ID: ";
                    cin >> patid;
                    cout << "Enter the Patient name: ";
                    cin >> patname;
                    p1 = Patient(patid, patname);

                    Node *deptNode = hms.searchDepartment(hms.droot, dept);
                    if (deptNode != nullptr)
                    {
                        deptNode->pat = hms.InsertionOfPatient(deptNode->pat, p1);
                    }
                }
            }
            break;

        case 2:
            cout << "Enter the Department ID Where Patient is Located: ";
            cin >> dept;
            cout << "Enter the Patient Id Which is Going to Discharge: ";
            cin >> patid;
            hms.dichargePatient(dept, patid);
            break;

        case 3:
            cout << "Displaying Departments and Patients: " << endl;
            hms.displayDepartments(hms.droot);
            break;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}


