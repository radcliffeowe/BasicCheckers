/*
 * Space.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef SPACE_H_
#define SPACE_H_

class Space {
public:
	Space();
	virtual ~Space();
	void setDark();
	bool getDark();
	void setRow(int);
	int getRow();
	void setCol(int);
	int getCol();
	virtual void setBlack() = 0;
	virtual bool getBlack() = 0;
	virtual int getSpaceType() = 0;
	void setSpaceType(int type);
private:
	int row;
	int col;
	bool dark;
	int spaceType;
};

#endif /* SPACE_H_ */
