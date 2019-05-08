#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include "student.h"
#include "project.h"

using namespace std;

template<typename V, typename Callable>
void for_each_combination(V &v, vector<project> p, size_t gp_sz, Callable f) {
    V gp(gp_sz);
    auto total_n = pow(v.size(), gp.size());
    for (auto i = 0; i < total_n; ++i) {
        auto n = i;
        bool res[v.size()];
        for(int k=0;k<v.size();k++)
            res[k]=false;
        for (auto j = 0ul; j < gp.size(); ++j) {
            gp[gp.size() - j - 1] = v[n % v.size()];
            n /= v.size();
        }

        for (auto c: gp){
            for(int l=0;l<v.size();l++){
                if(c.name==p[l].name)
                    res[l]=true;
            }
        }
        bool salida = false;
        for(int m=0;m<v.size();m++){
            if(!res[m])
                salida = true;
        }
        if(!salida){
            f(gp);
        }
    }
}

struct node
{
    pair<student,project> data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }

    void add_node(pair<student,project> n){
        node *tmp = new node;
        tmp->data.first = n.first;
        tmp->data.second = n.second;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void deleteNode(node *head, node *n){
        if(head == n)
        {
            if(head->next == NULL)
            {
                cout << "There is only one node." <<
                        " The list can't be made empty ";
                return;
            }
            head->data = head->next->data;
            n = head->next;
            head->next = head->next->next;
            free(n);
            return;
        }
        node *prev = head;
        while(prev->next != NULL && prev->next != n)
            prev = prev->next;
        if(prev->next == NULL){
            cout << "\nGiven node is not present in Linked List";
            return;
        }
        prev->next = prev->next->next;
        free(n);

        return;
    }

     void display(int n){
          node* ptr;
          ptr = head;
          int c = 0;
          while (ptr != NULL) {
              if(c==n){
                cout << endl;
                c=0;
              }
              cout<< ptr->data.first.name <<"-"<<ptr->data.second.name<<" ";
              ptr = ptr->next;
              c++;
          }
     }

     void deletex(int id){
          node* ptr;
          ptr = head;
          while (ptr != NULL) {
              if(ptr->data.first.id == id){
                deleteNode(head,ptr);
              }
                ptr = ptr->next;
          }
     }

     void redistribute(int n,vector<project> p){
        bool res[n];
        for(int i=0;i<n;i++){
            res[i]=false;
        }
        node* ptr;
        ptr = head;
        int cont = 0;
        vector<node*> masivo;
        while (ptr != NULL) {
            masivo.push_back(ptr);
            for(int i = 0;i<n;i++){
                if(ptr->data.second.id == p[i].id){
                    res[i]=true;
                }
            }

            cont++;
            if(cont == n){
                bool xxx=true;
                for(int i=0;i<n;i++){
                    if(res[i]!=true)
                        xxx=false;
                }
                if(!xxx){
                    for(int i = 0;i<n;i++){
                        if(masivo[i]==head){
                            for(int j=0;j<n;j++)
                                deleteNode(head,masivo[0]);
                            break;
                        }
                        else
                        deleteNode(head,masivo[i]);
                    }

                }
                masivo.clear();
                cont = 0;
                for(int i=0;i<n;i++)
                    res[i]=false;
            }
            ptr = ptr->next;

        }
     }

     void replace_project(string nuevo, int id){
          node* ptr;
          ptr = head;
          while (ptr != NULL) {
              if(ptr->data.second.id==id){
                ptr->data.second.name = nuevo;
              }
              ptr = ptr->next;

          }
     }

};

int main() {

    int n,k;
        cout << "Introduce the number of students: ";
        cin >> n;
        cout << "Introduce the number of projects: ";
        cin >> k;
        while(k>n){
            cout << "The number of students must be greater than or equal to the number of projects. Introduce the number of projects: ";
            cin >> k;
        }

        vector<student> students(n);
        vector<project> projects(k);

        for(int i=0; i<n; i++){
            cout << "Introduce the name of student "<< i << ": ";
            cin >> students[i].name;
            students[i].id=i;
        }
        for(int i=0; i<k; i++){
            cout << "Introduce the name of project "<< i << ": ";
            cin >> projects[i].name;
            projects[i].id = i;
        }
        //1.1
        for_each_combination(projects, projects, n, [&](vector<project> &gp) {
        int contador = 0;
            for (auto c: gp){
                cout << students[contador].name << "-" << project(c).name << " ";
                contador++;
            }
            cout << endl;
        });

        cout << endl << endl;
        //1.2
        linked_list a;
        for_each_combination(projects, projects, n, [&](vector<project> &gp) {
            int contador = 0;
            for (auto c: gp){
                    a.add_node(make_pair(students[contador],project(c)));
                contador++;
            }
        });

        cout << "The following display is using a linked-list:\n";
        a.display(n);

        //1.3
        int x;
        cout << endl << "\nID of the student you want to delete: ";
        cin >> x;
        a.deletex(x);
        a.redistribute(n-1, projects);
        cout << "\nThe following display is without the student:\n";
        a.display(n-1);

        //1.4
        int z;
        string new_name;
        cout << "\n\nEnter the id of the subject you want to change: ";
        cin >> z;
        cout << "\n\nEnter the new name: ";
        cin >> new_name;
        a.replace_project(new_name,z);
        a.display(n-1);

        cout << endl;

}
