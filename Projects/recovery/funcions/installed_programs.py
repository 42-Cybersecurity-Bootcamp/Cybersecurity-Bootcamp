import subprocess 
  
Data = subprocess.check_output(['wmic', 'product', 'get', 'name']) 
a = str(Data) 
  
try: 
    
    
    for i in range(len(a)): 
        print(a.split("\\r\\r\\n")[6:][i]) 
  
except IndexError as e: 
    print("All Done")