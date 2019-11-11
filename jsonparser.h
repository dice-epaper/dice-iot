String json_parser(String s, String a) {    
  String val;
  if (s.indexOf(a) != -1) {                                                   
    int st_index = s.indexOf(a);                                        
    int val_index = s.indexOf(':', st_index);                  
    if (s.charAt(val_index + 2) == '"') {                         
      int ed_index = s.indexOf('"', val_index + 3);       
      val = s.substring(val_index + 3, ed_index);        
    }
    
  } 
  else {
    val = "none";    
  }
  return val;
}
