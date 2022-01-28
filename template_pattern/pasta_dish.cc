#include <iostream>

class PastaDish {
 public:
  PastaDish(int pasta_cooking_time_min) : pasta_cooking_time_min_(pasta_cooking_time_min) {}
  void makeRecipe() {
    boilWater();
    addPasta();
    cookPasta();
    addSauce();
    addProtein();
    addGarnish();

    std::cout << "et Voila! Bon apetit! :)\n\n";
  };

  virtual void addPasta() = 0;
  virtual void addSauce() = 0;
  virtual void addProtein() = 0;
  virtual void addGarnish() = 0;

  void boilWater() const { std::cout << "Boiling water...\n"; }
  void cookPasta() { std::cout << "Cooking pasta for " << pasta_cooking_time_min_ << " mins...\n"; }
  int pasta_cooking_time_min_ = 0;
};

class SpaghettiMeatBalls : public PastaDish {
 public:
  SpaghettiMeatBalls() : PastaDish(8) {}
  void addPasta() { std::cout << "Add Spaghetti...\n"; }
  void addProtein() { std::cout << "Add meatballs...\n"; }
  void addSauce() { std::cout << "Add tomato sauce...\n"; }
  void addGarnish() { std::cout << "Add Parmesan cheese...\n"; }
};

class PenneAlfredo : public PastaDish {
 public:
  PenneAlfredo() : PastaDish(10) {}
  void addPasta() { std::cout << "Add Penne...\n"; }
  void addProtein() { std::cout << "Add checken...\n"; }
  void addSauce() { std::cout << "Add Alfredo sauce...\n"; }
  void addGarnish() { std::cout << "Add parsley...\n"; }
};

int main() {
  SpaghettiMeatBalls spaghetti_meat_balls;
  spaghetti_meat_balls.makeRecipe();

  PenneAlfredo penne_alfredo;
  penne_alfredo.makeRecipe();
  return 0;
}
