import random
import string
WORDLIST_FILENAME = "words.txt"

def chooseWord(wordlist):
    return random.choice(wordlist)

def hangman(secretWord):
    print "Welcome to the game Hangman!"
    print "I am thinking of the word that is ", len(secretWord), "letters long. "
    print "............"
    lettersGuessed=[]
    mistakesMade=0
    avialableLetters=string.ascii_lowercase
    while mistakesMade<8 and not isWordGuessed(secretWord, lettersGuessed):
        

secretWord=chooseWord(wordlist).lower()
hangman(secretWord)
