#ifndef BUILDER_H
#define BUILDER_H

class Builder
{
public:
	virtual void buildHead() {}
	virtual void buildBody() {}
	virtual void buildArms() {}
	virtual void buildLegs() {}
	virtual void buildFeet() {}

protected:
	Builder();
		
};

class ThinBuilder : public Builder
{
public:
	ThinBuilder();
	
	void buildHead();
	void buildBody();
	void buildArms();
	void buildLegs();
	void buildFeet();

};

class FatBuilder : public Builder
{
public:
	FatBuilder();
	
	void buildHead();
	void buildBody();
	void buildArms();
	void buildLegs();
	void buildFeet();
};



#endif

