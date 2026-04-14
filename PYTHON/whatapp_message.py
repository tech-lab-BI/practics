import pywhatkit as kit

# Phone number with country code
phone_number = "+91 8420406319"
message = "Hello! This message is sent using Python"

# Send instantly (opens WhatsApp Web)
kit.sendwhatmsg_instantly(phone_number, message)

print("Message sent successfully!")