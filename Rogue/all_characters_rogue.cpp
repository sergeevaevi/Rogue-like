#include "rogue.h"


Character::Character() : hp_(0), damage_(0), sym_(SYM), pos_x_(-1), pos_y_(-1) {};

Projectile::Projectile() :
	direction_y_(0), direction_x_(0),
	hp_(1), damage_(KNIGHT_PROJ), sym_(PROJ_K_SYM),
	pos_y_(0), pos_x_(0) {};
Projectile::~Projectile() {}
Projectile::Projectile(int dir_x, int dir_y, int damage, int pos_x, int pos_y, char sym) {
	direction_x_ = dir_x;
	direction_y_ = dir_y;
	hp_ = 1;
	damage_ = damage;
	sym_ = sym;
	pos_x_ = pos_x;
	pos_y_ = pos_y;
}
int Projectile::getDamage() const {
	return damage_;
}
char Projectile::getSym() const {
	return sym_;
}
int Projectile::getHp() const {
	return hp_;
}
void Projectile::setHp(int) {}
void Projectile::setDamage(int damage) {
	damage_ = damage;
}
void Projectile::setSym(char sym) {
	sym_ = sym;
}
void Projectile::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Projectile::collide(Character &C) {
	C.collideWith(*this);
	C.setHp(C.getHp() - this->getDamage());
}
void Projectile::collideWith(Princess &) {
	printw("Auch! \n");
	refresh();
}
void Projectile::collideWith(Knight &) {}
void Projectile::collideWith(Zombie &) {}
void Projectile::collideWith(Dragon &) {}
void Projectile::collideWith(Projectile &) {}
void Projectile::collideWith(Aid & A) {
	A.setStage(true);
}
int Projectile::getDirX()  const {
	return direction_x_;
}
int Projectile::getDirY() const {
	return direction_y_;
}
int Projectile::getPosX() const {
	return pos_x_;
}
int Projectile::getPosY() const {
	return pos_y_;
}

Knight::Knight() {
	setPos(0, 0);
	setHp(DEFAULT_HP);
	setDamage(DEFAULT_DAMAGE);
	setSym(K_SYM);
	victory_ = false;
}
Knight::~Knight() {}
int Knight::getHp() const {
	return hp_;
}
int Knight::getDamage()const {
	return damage_;
}
char Knight::getSym() const {
	return sym_;
}
int Knight::getPosX()const {
	return pos_x_;
}
int Knight::getPosY()const {
	return pos_y_;
}
void Knight::setHp(int hp) {
	hp_ = hp;
}
void Knight::setDamage(int damage) {
	damage_ = damage;
}
void Knight::setSym(char sym) {
	sym_ = sym;
}
void Knight::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Knight::collide(Character &C) {
	C.collideWith(*this);
	C.setHp(C.getHp() - this->getDamage());
}
void Knight::collideWith(Princess &) {
	printw("WiN");
	victory_ = true;
}
void Knight::collideWith(Zombie &Z) {
	printw("Zombie attack Knight! \n");
	Z.setHp(Z.getHp() - this->getDamage());
	refresh();
}
void Knight::collideWith(Dragon &D) {
	printw("Dragon attack Knight! \n");
	D.setHp(D.getHp() - this->getDamage());
}
void Knight::collideWith(Knight &) {}
void Knight::collideWith(Projectile &) {
	printw("Knight was a little fried! \n");
}
void Knight::collideWith(Aid & A) {
	printw("Aid was eaten! \n");
	//A.setHp(A.getHp() - 2*this->getDamage());
	A.setStage(true);
}
int Knight::getDirX()const {
	return direction_x_;
}
int Knight::getDirY()const {
	return direction_y_;
}
bool Knight::isVictory() {
	return victory_;
}
void Knight::setDirX(int dir_x) {
	if (dir_x) {
		direction_x_ = dir_x / abs(dir_x);
	}
	else {
		direction_x_ = dir_x;
	}
}
void Knight::setDirY(int dir_y) {
	if (dir_y) {
		direction_y_ = dir_y / abs(dir_y);
	}
	else {
		direction_y_ = dir_y;
	}
}

Princess::Princess() {
	setHp(DEFAULT_HP);
	setDamage(0);
	setSym(P_SYM);
	victory_ = false;
}
Princess::~Princess() {}
int Princess::getHp()const {
	return hp_;
}
int Princess::getDamage()const {
	return damage_;
}
char Princess::getSym()const {
	return sym_;
}
int Princess::getPosX() const {
	return pos_x_;
}
int Princess::getPosY()const {
	return pos_y_;
}
void Princess::setHp(int hp) {
	hp_ = hp;
}
void Princess::setDamage(int damage) {
	damage_ = damage;
}
void Princess::setSym(char sym) {
	sym_ = sym;
}
void Princess::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Princess::collide(Character &C) {
	C.collideWith(*this);
}
void Princess::collideWith(Princess &) {}
void Princess::collideWith(Zombie &) {
}
void Princess::collideWith(Dragon &) {
}
void Princess::collideWith(Knight &) {
	printw("WIN \n");
	victory_ = true;
}
void Princess::collideWith(Projectile &V) {
	this->setHp(this->getHp() + V.getDamage());
}
void Princess::collideWith(Aid &) {}
bool Princess::isVictory() {
	return victory_;
}

Zombie::Zombie() {
	setHp(ZOMBIE_HP);
	setDamage(ZOMBIE_DAMAGE);
	setSym(Z_SYM);
};
Zombie::~Zombie() {}
int Zombie::getHp() const {
	return hp_;
}
int Zombie::getDamage()const {
	return damage_;
}
char Zombie::getSym()const {
	return sym_;
}
int Zombie::getPosX()const {
	return pos_x_;
}
int Zombie::getPosY()const {
	return pos_y_;
}
void Zombie::setHp(int hp) {
	hp_ = hp;
}
void Zombie::setDamage(int damage) {
	damage_ = damage;
}
void Zombie::setSym(char sym) {
	sym_ = sym;
}
void Zombie::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Zombie::collide(Character &C) {
	C.collideWith(*this);
	C.setHp(C.getHp() - this->getDamage());
}
void Zombie::collideWith(Princess &) {
}
void Zombie::collideWith(Zombie &Z) {
	printw("Zombie attack Zombie :))\n");
	Z.setHp(Z.getHp() - this->getDamage());
}
void Zombie::collideWith(Dragon &D) {
	D.setHp(D.getHp() - this->getDamage());
}
void Zombie::collideWith(Knight &K) {
	K.setHp(K.getHp() - this->getDamage());
}
void Zombie::collideWith(Projectile &V) {
	V.setHp(V.getHp() - this->getDamage());
}
void Zombie::collideWith(Aid &A) {
	printw("Zombie get Aid\n");
	A.setHp(A.getHp() - this->getDamage());
	A.setStage(true);
}

Dragon::Dragon() : defeated_(false) {
	setHp(DRAGON_HP);
	setDamage(DRAGON_DAMAGE);
	setSym(D_SYM);
};
Dragon::~Dragon() {}
int Dragon::getHp()const {
	return hp_;
}
int Dragon::getDamage()const {
	return damage_;
}
char Dragon::getSym()const {
	return sym_;
}
int Dragon::getPosX()const {
	return pos_x_;
}
int Dragon::getPosY()const {
	return pos_y_;
}
void Dragon::setHp(int hp) {
	hp_ = hp;
}
void Dragon::setDamage(int damage) {
	damage_ = damage;
}
void Dragon::setSym(char sym) {
	sym_ = sym;
}
void Dragon::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Dragon::collide(Character &C) {
	C.collideWith(*this);
	printw("%d\n", C.getHp());
	refresh();
	C.setHp(C.getHp() - this->getDamage());
	printw("%d\n", C.getHp());
	refresh();
}
void Dragon::collideWith(Princess &) {
}
void Dragon::collideWith(Zombie &Z) {
	Z.setHp(Z.getHp() - this->getDamage());
}
void Dragon::collideWith(Dragon &D) {
	D.setHp(D.getHp() - this->getDamage());
}
void Dragon::collideWith(Knight &K) {
	K.setHp(K.getHp() - this->getDamage());
	printw("Knight attack Dragon\n");
}
void Dragon::collideWith(Projectile &) {
	printw("Dragon got a bullet\n");
	refresh();
	//V.setHp(V.getHp() - this->getDamage());
}
void Dragon::collideWith(Aid &A) {
	printw("Dragon eat your Aid\n");
	A.setHp(A.getHp() - this->getDamage());
	A.setStage(true);
}
void Dragon::setDirY(int dir_y) {
	direction_y_ = dir_y;
}
bool Dragon::isDefeated() {
	return defeated_;
}
void Dragon::defeat() {
	defeated_ = true;
}
int Dragon::getDirX()const {
	return direction_x_;
}
int Dragon::getDirY()const {
	return direction_y_;
}
void Dragon::setDirX(int dir_x) {
	direction_x_ = dir_x;
}

Aid::Aid() {
	setSym(A_SYM);
	setDamage(-DRAGON_DAMAGE);
	setHp(1);
}
Aid::~Aid() {}
Aid::Aid(int x, int y) {
	setSym('u');
	setDamage(-50);
	setHp(1);
	setPos(x, y);
}
int Aid::getHp()const {
	return hp_;
}
int Aid::getDamage()const {
	return damage_;
}
char Aid::getSym()const {
	return sym_;
}
int Aid::getPosX()const {
	return pos_x_;
}
int Aid::getPosY()const {
	return pos_y_;
}
void Aid::setHp(int hp) {
	hp_ = hp;
}
void Aid::setDamage(int damage) {
	damage_ = damage;
}
void Aid::setSym(char sym) {
	sym_ = sym;
}
void Aid::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Aid::collide(Character &C) {
	C.collideWith(*this);
	C.setHp(C.getHp() - this->getDamage());
	is_wasted_ = true;
}
void Aid::collideWith(Princess &C) {
	C.setHp(C.getHp() - this->getDamage());
}
void Aid::collideWith(Zombie &C) {
	C.setHp(C.getHp() - this->getDamage());
}
void Aid::collideWith(Dragon &C) {
	C.setHp(C.getHp() - this->getDamage());
}
void Aid::collideWith(Knight &C) {
	C.setHp(C.getHp() - this->getDamage());
	is_wasted_ = true;
}
void Aid::collideWith(Projectile &) {}
void Aid::collideWith(Aid &C) {}
void Aid::setStage(bool change) {
	is_wasted_ = change;
}
bool Aid::getStage() const {
	return is_wasted_;
}


Wall::Wall() {
	setSym(W_SYM);
	setDamage(1);
	setHp(0);
}
Wall::~Wall() {}
Wall::Wall(int x, int y) {
	setSym('#');
	setDamage(1);
	setHp(0);
	setPos(x, y);
}
int Wall::getHp()const {
	return hp_;
}
int Wall::getDamage()const {
	return damage_;
}
char Wall::getSym()const {
	return sym_;
}
int Wall::getPosX() const {
	return pos_x_;
}
int Wall::getPosY()const {
	return pos_y_;
}
void Wall::setHp(int hp) {
	hp_ = hp;
}
void Wall::setDamage(int damage) {
	damage_ = damage;
}
void Wall::setSym(char sym) {
	sym_ = sym;
}
void Wall::setPos(int x, int y) {
	pos_x_ = x;
	pos_y_ = y;
}
void Wall::collide(Character &C) {
	C.setHp(C.getHp() - this->getDamage());
}
void Wall::collideWith(Princess &) {
}
void Wall::collideWith(Zombie &) {
}
void Wall::collideWith(Dragon &) {
}
void Wall::collideWith(Knight &) {
}
void Wall::collideWith(Projectile &) {}
void Wall::collideWith(Aid &) {
}