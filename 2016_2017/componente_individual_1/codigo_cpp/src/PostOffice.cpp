/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>
#include <iostream>

PostOffice::PostOffice(string firstZCode, string lastZCode) :
		firstZipCode(firstZCode), lastZipCode(lastZCode) {
}
PostOffice::PostOffice() {
}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p) {
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

//Exercicio b ////////////////////////////////////////////////////////////////////////////////

vector<Mail *> PostOffice::removePostman(string name) {

	for (vector<Postman>::iterator it = postmen.begin(); it != postmen.end();
			it++) {
		if (it->getName() == name) //se encontrou o carteiro com esse nome
				{
			vector<Mail *> mail;
			mail = it->getMail(); //guarda o correio atribuido a esse carteiro
			postmen.erase(it); //apaga esse carteiro do vetor
			return mail;
		}
	}

	return {};  //se nao encontrou o carteiro com esse nome
}

//Exercicio d ///////////////////////////////////////////////////////////////////////////

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {

	vector<Mail *> v1;
	balance=0;

	for (vector<Mail *>::iterator it = mailToSend.begin();
			it != mailToSend.end(); it++) {
		balance += (*it)->getPrice(); //adiciona o preco da correspondencia ao valor balance

		if ((((*it)->getZipCode()) >= firstZipCode)
				&& (((*it)->getZipCode()) <= lastZipCode)) //se o zipcode estiver na gama definida pela estacao
			addMailToDeliver(*it); //adiciona o correio ao vetor mailToDeliver
		else
			v1.push_back(*it);

	}
	mailToSend= {}; //esvaziar o vetor
	return v1;

}

//Exercicio g ////////////////////////////////////////////////////////////////////////

Postman PostOffice::addMailToPostman(Mail *m, string name) {
try
{
	for(int i=0;i<postmen.size();i++)
	{
		if(postmen.at(i).getName()==name) //se encontrou o carteiro de nome 'name'
		{
			postmen.at(i).addMail(m); //adiciona a correspondência ao vetor myMail desse carteiro
			return postmen.at(i);//retorna esse carteiro
		}
	}
	//se não existe um carteiro com esse nome...

	throw NoPostmanException(name);
}
catch(NoPostmanException &exception)
{
	cout<<"Carteiro "<<exception.getName()<<" nao existe! \n";
	throw;
}

}
