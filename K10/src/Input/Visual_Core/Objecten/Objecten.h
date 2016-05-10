/*
 * Objecten.h
 *
 *  Created on: 28-mrt.-2016
 *      Author: david12
 */

#ifndef VISUAL_CORE_OBJECTEN_OBJECTEN_H_
#define VISUAL_CORE_OBJECTEN_OBJECTEN_H_



class Objecten {
public:
	Objecten(int,int,int,int[]);
	virtual ~Objecten();

	int* getData() const {
		return data;
	}

	void setData(int* data) {
		this->data = data;
	}

	void setId(char id) {
		ID = id;
	}

	void setId(int id) {
		pID = id;
	}

	char getSoort() const {
		return soort;
	}

	void setSoort(char soort) {
		this->soort = soort;
	}

private:
	char ID;
	char soort;
	/*
	 * 0=mens
	 * 1=bal
	 * 2=bort
	 */
	int  pID;
	int* data;
};

#endif /* VISUAL_CORE_OBJECTEN_OBJECTEN_H_ */
