from cards import Deck, Card
 
 
class Player(object):
 
    def __init__(self, cards):
        self._cards = cards
        self._wins = 0
        self._losses = 0
 
    def __str__(self):
        result = str(self._cards)
        return result
 
    def increment_win(self):  # used as a setter
        self._wins += 1
 
    def increment_loss(self):  # used as a setter
        self._losses += 1
 
    def get_win(self):  # getter
        return self._wins
 
    def get_loss(self):  # getter
        return self._losses
 
    @property  # property to be accessed in the game function
    def get_card(self):
        if (self._cards.rank==1):
            return Card(14,self._cards.suit)
        else:
            return self._cards
 
    def draw_card(self, deck):
        self._cards=deck.deal()  # take a new card from the deck
 
 
class Dealer(Player):  # has nothing special
    pass  # same as the player class
 
 
class DeadOrAlive(object):
 
    def __init__(self):  # similar to the blackjack
        self._deck = Deck()
        self._deck.shuffle()
        # we only draw/ have one card initially
        self._player = Player(self._deck.deal())
        self._dealer = Dealer(self._deck.deal())
 
    def play(self):
        round = 1  # for convenience count the rounds
        # I need this part to read the very first values
        print("\nROUND:", round)
        # show intermediate steps
        print("You:\n", self._player)
        print("Dealer:\n", self._dealer)
        if self._player.get_card > self._dealer.get_card:
            print("You won now! :)")
            self._player.increment_win()
            self._dealer.increment_loss()
        elif self._player.get_card < self._dealer.get_card:  # self explanatory
            print("Dealer won now! :(")
            self._dealer.increment_win()
            self._player.increment_loss()
        else:
            count=2
            while True:
                self._player.draw_card(self._deck)
                self._dealer.draw_card(self._deck)
                print("\nROUND:", round)
                print("You:\n", self._player)
                print("Dealer:\n", self._dealer)
                if self._player.get_card > self._dealer.get_card:
                    print("You won now! :)")
                    for i in range(count):#if player wins then set all draws till now as wins for player
                        self._player.increment_win()
                        self._dealer.increment_loss()
                    break
                elif self._player.get_card < self._dealer.get_card:  # if dealer wins then set all draws till now as wins for dealer
                    print("Dealer won now! :(")
                    for i in range(count):
                        self._dealer.increment_win()
                        self._player.increment_loss()
                    break
                else:
                    count+=1
                    continue
 
        while self._deck:
            # repeat the same strategy for the whole deck
            round += 1
            self._player.draw_card(self._deck)
            self._dealer.draw_card(self._deck)
            print("\nROUND:", round)
            print("You:\n", self._player)
            print("Dealer:\n", self._dealer)
            if self._player.get_card > self._dealer.get_card:
                print("You won now! :)")
                self._player.increment_win()
                self._dealer.increment_loss()
            elif self._player.get_card < self._dealer.get_card:  # self explanatory
                print("Dealer won now! :(")
                self._dealer.increment_win()
                self._player.increment_loss()
            else:
                count=2
                while True:
                    self._player.draw_card(self._deck)
                    self._dealer.draw_card(self._deck)
                    print("\nROUND:", round)
                    print("You:\n", self._player)
                    print("Dealer:\n", self._dealer)
                    if self._player.get_card > self._dealer.get_card:
                        print("You won now! :)")
                        for i in range(count):#if player wins then set all draws till now as wins for player
                            self._player.increment_win()
                            self._dealer.increment_loss()
                        break
                    elif self._player.get_card < self._dealer.get_card:  # if dealer wins then set all draws till now as wins for dealer
                        print("Dealer won now! :(")
                        for i in range(count):
                            self._dealer.increment_win()
                            self._player.increment_loss()
                        break
                    else:
                        count+=1
                        continue
 
        # show the final 'statistical' information
        print("\n\nYou have", self._player.get_win(), "wins")
        print("You have", self._player.get_loss(), "losses")
        print("Dealer has", self._dealer.get_win(), "wins")
        print("Dealer has", self._dealer.get_loss(), "losses\n")
 
        # determine the global winner
        if self._player.get_win() > self._dealer.get_win():
            print("You are the BIG winner")
        elif self._player.get_win() < self._dealer.get_win():
            print("The dealer is the BIG winner")
        else:  # == (13 and 13 wins)
            print("Draw!")
 
 
def main():  # similar to the black jack main
    game = DeadOrAlive()
    game.play()
 
 
main()