#include <iostream>
#include <string>

class State;
class Idle;
class HasDollar;
class VendingMachine;

class State {
 public:
  State(const std::string& name) : name_(name) {}
  virtual ~State() { std::cout << "Destructing state " << name_ << "\n"; }

  virtual void insertDollar(VendingMachine& vending_machine) = 0;
  virtual void ejectMoney(VendingMachine& vending_machine) = 0;
  virtual void dispense(VendingMachine& vending_machine) = 0;
  std::string name_;
};

// Or context
class VendingMachine {
 public:
  VendingMachine(State* state) : current_state_(nullptr) {
    if (state) {
      setState(state);
    }
  }
  ~VendingMachine() { delete current_state_; }
  void setState(State* new_state) {
    std::cout << "Transition to new state " << new_state->name_ << "\n";
    if (current_state_) {
      delete current_state_;
    }
    current_state_ = new_state;
  }

  void returnMoney() { std::cout << "Return $...\n"; }
  void releaseProduct() { std::cout << "Releasing those chocolate bars...\n"; }
  void dispense() { current_state_->dispense(*this); }
  void insertDollar() { current_state_->insertDollar(*this); }

 private:
  State* current_state_;
};

class Idle : public State {
 public:
  Idle() : State("idle") {}
  void insertDollar(VendingMachine& vending_machine) override;
  void ejectMoney(VendingMachine& vending_machine) override {}
  void dispense(VendingMachine& vending_machine) override {}
};

class HasDollar : public State {
 public:
  HasDollar() : State("has_dollar") {}

  void insertDollar(VendingMachine& vending_machine) override { std::cout << " Already has money.\n"; }
  void ejectMoney(VendingMachine& vending_machine) override {
    vending_machine.returnMoney();
    State* new_state = new Idle();
    vending_machine.setState(new_state);
  }
  void dispense(VendingMachine& vending_machine) override { vending_machine.releaseProduct(); }
};

void Idle::insertDollar(VendingMachine& vending_machine) {
  std::cout << " $ inserted.\n";
  State* new_state = new HasDollar();
  vending_machine.setState(new_state);
}

int main() {
  VendingMachine vending_machine(new Idle());
  vending_machine.insertDollar();
  return 0;
}
