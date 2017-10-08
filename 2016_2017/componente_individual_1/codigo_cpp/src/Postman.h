/*
 * Postman.h
 */

#ifndef SRC_POSTMAN_H_
#define SRC_POSTMAN_H_

#include "Mail.h"
#include <string>
#include <vector>

class Postman {
	unsigned int id;
	string name;
	vector<Mail *> myMail;
	static unsigned int nID; //para controlar o id a atribuir a cada carteiro. Começa igual a zero
public:
	Postman();
	Postman(string name) {this->name=name; nID++; this->id=nID; myMail={};}
	void setName(string nm);
	void addMail(Mail *m);
	void addMail(vector<Mail *> mails);
	string getName() const;
	vector<Mail *> getMail() const;
	unsigned int getID() const;
	bool operator<(Postman &p2);
};


#endif /* SRC_POSTMAN_H_ */
