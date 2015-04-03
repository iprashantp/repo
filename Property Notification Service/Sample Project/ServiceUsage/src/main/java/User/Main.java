package User;

import java.io.IOException;
import java.util.HashSet;
import org.apache.commons.configuration.ConfigurationException;
import PropertyNotifier.NotificationHandler;
import PropertyNotifier.WatchServiceManager;


public class Main implements NotificationHandler{
	public static void main(String[] args) throws ConfigurationException, IOException {
		Main callerObj=new Main();
		WatchServiceManager serviceObj= WatchServiceManager.GetInstance();
		String file_name1="E:\\Configurations\\config1.properties";
		String file_name2="E:\\Configurations\\config2.properties";
		String file_name3="E:\\Configurations\\config3.properties";
		String file_name4="E:\\Configurations\\config4.properties";
		String file_name5="E:\\Configuration2\\config5.properties";
		String file_name6="E:\\Configurations\\Configurations3\\config6.properties";
		HashSet<String> registerSet=new HashSet<String>();
		HashSet<String> registerSet2=new HashSet<String>();
		HashSet<String> registerSet3=new HashSet<String>();
		HashSet<String> registerSet4=new HashSet<String>();
		registerSet.add("a");
		registerSet.add("b");
		registerSet.add("c");
		registerSet.add("d");
		registerSet.add("f");
		serviceObj.Register(file_name1, registerSet, callerObj);
		serviceObj.Register(file_name1, "b", callerObj);
		serviceObj.Register(file_name1, "b", callerObj);
		serviceObj.Register(file_name1,registerSet , callerObj);
		
		registerSet2.add("value1");
		registerSet2.add("value2");
		registerSet2.add("value3");
		registerSet2.add("value4");
		serviceObj.Register(file_name2, registerSet2, callerObj);
		serviceObj.Register(file_name2, "value1", callerObj);
		
		registerSet3.add("property1");
		registerSet3.add("property2");
		registerSet3.add("property3");
		serviceObj.Register(file_name3, registerSet3, callerObj);
		
		serviceObj.DeRegister(file_name3, "property2", callerObj);
		serviceObj.DeRegister(file_name3, "property2", callerObj);
		//registerSet.clear();
		registerSet4.add("file1");
		registerSet4.add("file2");
		registerSet4.add("file3");
		serviceObj.Register(file_name4, registerSet4, callerObj);
		serviceObj.Register(file_name4, registerSet4, callerObj);
		serviceObj.DeRegister(file_name4, registerSet4, callerObj);
		serviceObj.Register(file_name4, registerSet4, callerObj);
		serviceObj.Register(file_name4, "file2", callerObj);
		
		
		registerSet.clear();
		registerSet.add("main1");
		registerSet.add("main2");
		registerSet.add("main3");
		serviceObj.Register(file_name5, "main2", callerObj);
		serviceObj.DeRegister(file_name5, "main1", callerObj);
		registerSet.clear();
		registerSet.add("change1");
		registerSet.add("change2");
		registerSet.add("change3");
		serviceObj.Register(file_name6, registerSet, callerObj);
		serviceObj.DeRegister(file_name6, "change3", callerObj);
	}

	//fileChangeStatus: 1-add,2-delete,3-modify
	public void NotifyChange(String file_name, String property,HashSet<String> updatedProperty_valueSet,int fileChangeStatus) {
		// TODO Auto-generated method stub
		System.out.print("file: "+file_name+"\nproperty "+property+"\nstatus ");
		if(fileChangeStatus==1){
			System.out.println("Delete");
		}else if(fileChangeStatus==2){
			System.out.println("ADD");
		}else if(fileChangeStatus==3){
			System.out.println("MODIFY");
		}
	}

}
