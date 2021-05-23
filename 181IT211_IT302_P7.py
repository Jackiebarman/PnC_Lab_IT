# import all classes / functions from the tkinter 
## Compile by Naman:)

from tkinter import *
from tkinter import messagebox


# Function for clearing the 
# contents of all entry boxes 
def clear_all() : 

	# whole content of entry boxes is deleted 
	prob_field.delete(0, END) 
	num_field.delete(0, END) 
	ppl_field.delete(0, END) 
	ans_field.delete(0, END) 
	
	
	prob_field.focus_set() 
def ncr(n, r): 
  
    return (fact(n) / (fact(r)  
                * fact(n - r))) 
  
def fact(n): 
  
    res = 1
      
    for i in range(2, n+1): 
        res = res * i 
          
    return res 


def equali(prob,num,ppl):
	return ncr(num,ppl)*pow(prob,ppl)*pow((1-prob),(num-ppl))
def valid(x):
	for i in x:
		if(i>='0' and i<='9'):
			continue
		else:
			return False
	return True



def calculate_prob(): 

	# get a content from entry box 
	prob = float(prob_field.get()) 
	
	
	n = (num_field.get()) 
	p = (ppl_field.get())
	if(valid(n)==False):
		messagebox.showerror("error", "Invalid Input in Total No of people")
	if(valid(p)==False):
		messagebox.showerror("error","Invalid Input in No of people needs to be cured")

	num=int(n)
	ppl=int(p)



	

	res=0 
	print(ncr(num,ppl))
	
	a=equali(prob,num,ppl)
	# print(pow(prob,ppl))
	# print(pow((1-prob),(n-ppl)))
	# print(a)
	for i in range(num,ppl-1,-1):
		res=res+equali(prob,num,i)
	print(res)

	

	# insert method inserting the 
	# value in the text entry box. 
	ans_field.insert(10, res) 

	

# Driver code 
if __name__ == "__main__" : 
	
	# Create a GUI window 
	root = Tk() 
	
	# Set the background colour of GUI window 
	root.configure(background = 'light green') 
	
	# Set the configuration of GUI window 
	root.geometry("400x250") 
	
	# set the name of tkinter GUI window 
	root.title("Binomial Probability Calculator") 
		
	
	label1 = Label(root, text = "Probability for curing : ", 
				fg = 'black') 
	
	
	label2 = Label(root, text = "Total number of people : ", 
				fg = 'black') 
		
	
	label3 = Label(root, text = "Exact number of people that needs to be cured:", 
				fg = 'black') 

	
	label4 = Label(root, text = "P(X>=x): ", 
				fg = 'black') 

	# grid method is used for placing 
	# the widgets at respective positions 
	# in table like structure . 

	# padx keyword argument used to set paading along x-axis . 
	# pady keyword argument used to set paading along y-axis . 
	label1.grid(row = 1, column = 0, padx = 10, pady = 10) 
	label2.grid(row = 2, column = 0, padx = 10, pady = 10) 
	label3.grid(row = 3, column = 0, padx = 10, pady = 10) 
	label4.grid(row = 5, column = 0, padx = 10, pady = 10) 

	# Create a entry box 
	# for filling or typing the information. 
	prob_field = Entry(root) 
	num_field = Entry(root) 
	ppl_field = Entry(root) 
	ans_field = Entry(root) 

	# grid method is used for placing 
	# the widgets at respective positions 
	# in table like structure . 
	
	# padx keyword argument used to set paading along x-axis . 
	# pady keyword argument used to set paading along y-axis . 
	prob_field.grid(row = 1, column = 1, padx = 10, pady = 10) 
	num_field.grid(row = 2, column = 1, padx = 10, pady = 10) 
	ppl_field.grid(row = 3, column = 1, padx = 10, pady = 10) 
	ans_field.grid(row = 5, column = 1, padx = 10, pady = 10) 

	# Create a Submit Button and attached 
	# to calculate_prob function 
	button1 = Button(root, text = "Submit", bg = "red", 
					fg = "black", command = calculate_prob) 
	
	# Create a Clear Button and attached 
	# to clear_all function 
	button2 = Button(root, text = "Clear", bg = "red", 
					fg = "black", command = clear_all) 
	
	button1.grid(row = 4, column = 1, pady = 10) 
	button2.grid(row = 6, column = 1, pady = 10) 

	# Start the GUI 
	root.mainloop()