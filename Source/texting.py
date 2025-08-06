import smtplib
import sys
import time
 
CARRIERS = {
    "att": "@mms.att.net",
    "tmobile": "@tmomail.net",
    "verizon": "@vtext.com",
    "sprint": "@messaging.sprintpcs.com",
    "xfinity": "@vtext.com"
}

PEOPLE = {"riley": "5716960602",
          "jack": "5712296872",
          "logan": "7138553047",
          "wilbert": "5714283447" 
}
 
EMAIL = "logan.g.johnson12@gmail.com"
PASSWORD = "iulseavdvmuuwkzj"
 
def send_message(phone_number, carrier, message):
    recipient = phone_number + CARRIERS[carrier]
    auth = (EMAIL, PASSWORD)
 
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    server.login(auth[0], auth[1])
 
    server.sendmail(auth[0], recipient, message)
 
 
if __name__ == "__main__":
    '''
    if len(sys.argv) < 4:
        print(f"Usage: python3 {sys.argv[0]} <PHONE_NUMBER> <CARRIER> <MESSAGE>")
        sys.exit(0)
    '''
    if len(sys.argv) < 2:
        print(f"Usage: python {sys.argv[0]} <PHONE_NUMBER>")
        sys.exit(0)
    #phone_number = sys.argv[1]
    #carrier = sys.argv[2]
    #message = sys.argv[3]
    phone_number = sys.argv[1] #PEOPLE["logan"]
    phone_number = "7138553047"
    carrier = "att"
    message = "Hello, this is a test message from Python script."

    sendMessage = message
    print("sending " + sendMessage + " to " + phone_number)
    send_message(phone_number, carrier, message)
    time.sleep(10)
    
    #
    #for i in range(20): 
    #    sendMessage = str(i) + message 
    #    print ("sending" + sendMessage) 
    #    send_message(phone_number, carrier, message)
    #    time.sleep(10)
    #
    