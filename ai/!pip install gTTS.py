!pip install gTTS
import nltk
import nltk.corpus
#Tokenization
from nltk.tokenize import word_tokenize
chess = "Samay Raina is the best chess streamer in the world"
nltk.download('punkt')
word_tokenize(chess)
#sentence tokenizer
from nltk.tokenize import sent_tokenize
chess2 = "Samay Raina is the best chess streamer in the world. Sagar Sh
ah is the best chess coach in the world"
sent_tokenize(chess2)
#Checking the number of tokens
len(word_tokenize(chess))
#bigrams and n-grams
astronaut = "Can anybody hear me or am I talking to myself? My mind is
running empty in the search for someone else" 
34
astronaut_token=(word_tokenize(astronaut))
list(nltk.bigrams(astronaut_token))
list(nltk.trigrams(astronaut_token))
list(nltk.ngrams(astronaut_token,5))
#Stemming
from nltk.stem import PorterStemmer
my_stem = PorterStemmer()
my_stem.stem("eating")
my_stem.stem("going")
my_stem.stem("shopping")
#pos-tagging
tom ="Tom Hanks is the best actor in the world"
tom_token = word_tokenize(tom)
nltk.download('averaged_perceptron_tagger')
nltk.pos_tag(tom_token)
#Named entity recognition
from nltk import ne_chunk
president = "Barack Obama was the 44th President of America"
president_token = word_tokenize(president)
president_pos = nltk.pos_tag(president_token)
nltk.download('maxent_ne_chunker')
nltk.download('words')
print(ne_chunk(president_pos))
from gtts import gTTS
from IPython.display import Audio
tts = gTTS('Hello Atul, How are you')
tts.save('1.wav')
sound_file = '1.wav'
Audio(sound_file, autoplay=True)