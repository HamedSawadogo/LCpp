#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Personne
{
protected:
	string lastName;
	string firstName;
	int age;
public:
	string getFirstName()const;
	string getLastName()const;
	int getAge()const;
	Personne(string lastName,string firstName,int age);
	~Personne();
	
};

/**
 * définition des getters 
 **/
string Personne::getFirstName()const{return this->firstName;}
string Personne::getLastName()const {return this->lastName;}
int Personne::getAge()const{return this->age;}
// constructeur
Personne::Personne(string firstName,string lastName,int age){
	this->lastName=lastName;
	this->firstName=firstName;
	this->age=age;
}
Personne::~Personne(){}


// classe Student Elève hérite de Personne
class Student :Personne
{
  private:
  	//attributs propores a l'élève
  	std::vector<double>notes;
  	static int nb_notes;
  	double moyenne;
  	string classe;
public:

    /**
	 * modificateurs
	*/
   bool  check(Student &student);
   void setStudent(int setChoice,Student &student);
	string getClasse()const;
	void setNotes(vector<double>notes);
	vector<double>getNotes()const;
	
	// 
	double plusForteNote()const;
	double calculateMean()const;
	void displayStudent()const;
	void addNote(double const note);
	void displayNotes(std::vector<double> notes)const;
	void saisirNotes();
	void deleteNote(double note);
	bool checkNotes()const;
	std::vector<double> triNotes();
	// 
	Student(string firstName,string lastName, string classe,int age);
	~Student();
	
};


Student::~Student(){}
//le nombre de note d'un étudiant
int Student::nb_notes=4;


bool Student::check(Student &student){
	return this==&student;
}
/**
 * modifier un etudiant
*/
void Student::setStudent(int set_choice,Student &student){
	switch (set_choice)
	{
    case 1:
	    this->firstName=student.getFirstName();
		 break;
	 case 2:
		  this->lastName=student.getLastName();
	 case 3:
		 this->age=student.getAge();
	 case 4:
		 this->classe=student.getClasse();
	 default:
		break;
	}
}
string Student::getClasse()const{return this->classe;}
/**
 * set les notes
*/
void Student::setNotes(vector<double>notes){
	this->notes=notes;
}
/**
 * obtenir les notes de l'elève
*/
vector<double>Student::getNotes()const{
	return this->notes;
}
//constructeur de l'Elève
Student::Student(string firstName,string lastName, string classe ,int age)
:Personne(firstName,lastName,age){
	this->classe=classe;
}

bool Student::checkNotes()const{
	return this->notes.empty();
}
/**
 * 
 *calcul de la plus forte note 
 **/
double Student::plusForteNote()const{
   int  imax=0;
	for (int i = 1; i <this->notes.size(); ++i)
	{
		if(this->notes[i]>this->notes[imax]){
			imax=i;
		}
	}
   return this->notes[imax];

}
/**
 * trier les notes de l'etudiant
 * 
 **/
std::vector<double> Student::triNotes(){
	if(this->checkNotes()){
		cout<<"auncune note pour le moment";
	}
	 for (int i = 0; i <this->notes.size(); ++i)
	 { 
		int imax=i;
		for (int j=i+1; j <this->notes.size(); ++j)
		{
		   if(this->notes[i]<this->notes[imax]){
				imax=j;
		   }
		}
	    double tmp=this->notes[i];
		this->notes[i]=this->notes[imax];
		this->notes[i]=tmp;
	 }
	 return this->notes;
}
/**
 * 
 * calculer la moyenne de l'etudiant
 * */
double Student::calculateMean()const{
	if(this->checkNotes()){
		cout<<"auncune note pour le moment";
	}
	double somme=0.0;
	for (int i = 0; i <this->notes.size(); ++i)
	{
		somme+=this->notes[i];
	}
	return somme/(this->notes.size());
}

/**
 * 
 * ajouter une note a la liste des notes
 **/ 
void Student::addNote(double  const note){
	this->notes.push_back(note);
}

//afficher l'eleve 
void Student::displayStudent()const
{
	cout<<"Nom : "<<this->firstName<<endl;
	cout<<"Prenom : "<<this->lastName<<endl;
	cout<<"classe : "<<this->classe<<endl;
	cout<<"age: "<<this->age<<" ans "<<endl;
	this->displayNotes(this->notes);
	cout<<"MoyGen: "<<this->calculateMean()<<" /20 "<<endl;

	cout<<" "<<endl;
}

/**
 * 
 * afficher les notes de l'elève
 **/ 
void Student::displayNotes(std::vector<double> notes)const{
	if(this->notes.empty()){
		cout<<"===========aucune note disponible pour le moment==========="<<endl;
	}
	cout<<"===========notes========="<<endl;
	for (int i = 0; i <this->notes.size(); ++i)
	{
		cout<<"note "<<(i+1)<<" : "<<this->notes.at(i)<<endl;
	}
}
/**
 * saisir les notes de l'elève
 **/
void Student::saisirNotes(){
	for (int i = 0; i <Student::nb_notes; ++i)
	{    
		double note(.0);
		cout<<" enter la note "<<(i+1)<<":  ";
		cin>>note;
		this->addNote(note);
	}
}
/**
 * 
 * Gestionnaire des Elèves
 * 
 * */
class Classe
{
private:
	std::vector<Student*> studentsList;
public:
	void premierClasse();
	void setStudents(std::vector<Student*> students);
	void displayStudents();
	void addStudent(Student *student);
	Classe(vector<Student*>students);
	~Classe();
	
};
/**
 * 
 **/
void Classe::premierClasse(){
	
	if(this->studentsList.empty()){
		return;
	}
	int imajeur=0;
   for (int i = 0; i <this->studentsList.size(); ++i)
   {
   	if(this->studentsList[imajeur]->calculateMean()<this->studentsList[i]->calculateMean()){
         imajeur=i;
   	}
   }
  this->studentsList[imajeur]->displayStudent();	
}
//liberation  de la memoire des étudiants
Classe::~Classe(){
	if(this->studentsList.size()>0){
		for (int i = 0; i <this->studentsList.size(); ++i)
		{
			delete this->studentsList[i];
		}
	}
}

Classe::Classe(vector<Student*>students){
  this->studentsList=students;
}
void Classe::displayStudents(){
	 cout<<"===========Liste des élèves==========="<<endl;	
   for (Student *std:this->studentsList)
   {
   	  std->displayStudent();
   }
}

void Classe::addStudent(Student *student){
	this->studentsList.push_back(student);
}
void Classe::setStudents(std::vector<Student*> students){
     this->studentsList=students;
} 
int main(int argc, char const *argv[])
{  
	vector<double>notes1={10,18,19,12};
	vector<double>notes2={15,8,19,11};
	vector<double>notes3={10,19,0,8};
	vector<double>notes4={10,3,4,13};
	vector<double>notes5={19,20,19,7};

   Student *student1=new Student("Ali ","Tom","5eme",13);
   student1->setNotes(notes1);

   Student *student2=new Student("keil","Toe","5eme",12);
   student2->setNotes(notes2);

   Student *student3=new Student("vim ","diff","5eme",14);
   student3->setNotes(notes3);

   Student *student4=new Student("Ker ","LAm","5eme",18);
   student4->setNotes(notes4);

   Student *student5=new Student("Mr","Yo","5eme",12);
   student5->setNotes(notes5);

	std::vector<Student*>studentsList;
	studentsList.push_back(student1);
	studentsList.push_back(student2);
	studentsList.push_back(student3);
	studentsList.push_back(student4);
	studentsList.push_back(student5);

   Classe *classe=new Classe(studentsList);

   classe->displayStudents();

   cout<<"******************PREMIER DE CLASSE*******************"<<endl;
   classe->premierClasse();
	// student->setNotes(notes);
	// vector<double>res=student->triNotes();
	// student->displayNotes(res);

	// Student s("or","Tle",19);
	// Student s2("or","Tle",19);

	// cout<<s.check(s2)<<endl;
	// cout<<&s<<endl;
	//vector<double>res=student->triNotes();
   /**
	* 
	student->displayStudent();
    student->saisirNotes();
    student->displayNotes(notes);
    cout<<"Moyenne Generale:   "<<student->calculateMean()<<" /20"<<endl;
    cout<<"La plus forte note est:   "<<student->plusForteNote()<<" /20"<<endl;
    cout<<"===========Liste des note par ordre croissant==========="<<endl;
    student->displayNotes(student->triNotes());
   */
    

	return 0;
}