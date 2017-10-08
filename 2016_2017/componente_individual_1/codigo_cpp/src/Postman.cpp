/*
 * Postman.cpp
 */
#include "Postman.h"

unsigned int Postman::nID=0; //variavel do tipo static da classe Postman

template <class T>
unsigned int numberDifferent (const vector<T> & v1)
{
    vector<T> v2;
    bool adiciona;

    for(int i=0;i<v1.size();i++)
    {
	    adiciona=true;

	    for(int i2=0;i2<v2.size();i2++)
	    {
		    if(v1.at(i)==v2.at(i2)) //se ja existir um elemento igual
		    {
			    adiciona=false;
			    break;
		    }
	    }

	    if(adiciona)
		    v2.push_back(v1.at(i));
    }


    return v2.size(); //numero de elementos diferentes no vetor
}


Postman::Postman(): id(0) {}


void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

//Exercicio f ////////////////////////////////////////////////////////////////////

bool Postman::operator<(Postman &p2)
{
	vector<string> zipCodes1,zipCodes2;

  for(int i=0;i<myMail.size();i++)
  {
	  zipCodes1.push_back(myMail.at(i)->getZipCode()); //adiciona o zipCode ao vetor zipCodes1
  }

  for(int i=0;i<p2.myMail.size();i++)
  {
	  zipCodes2.push_back(p2.myMail.at(i)->getZipCode()); //adiciona o zipCode ao vetor zipCodes2
  }

  if(numberDifferent(zipCodes1)<numberDifferent(zipCodes2))
	  return true;
  else
	  return false;

}

/////////////////////////////////////////////////////////////////////////////////

