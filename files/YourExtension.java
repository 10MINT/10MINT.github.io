package your.folder.YourExtension; //your package name must be in the folder structure /appinventor-sources/appinventor/components/src/your/folder/path
//import java libraries
import android.app.Activity;
import com.google.appinventor.components.annotations.*;
import com.google.appinventor.components.common.ComponentCategory;
import com.google.appinventor.components.common.PropertyTypeConstants;
import com.google.appinventor.components.runtime.*;

@DesignerComponent(version = 1, //your version number
    description = "This is the description of your component. " +     // this description appears in the components drawer
	              "To make the description easy to read for " +
				  "the developer, you can use a plus symbol (+) " +
				  "between the lines. Exclamation marks (\") are " +
				  "possible by writing a backslash infront of " +
				  "the actual character. You can also do some HTML " +
				  "formatting, such as: <ul><li>unordered lists,</li></ul>" +
				  "<ol><li>ordered lists,</li></ol><p>paragraphs, <b>bold " +
				  "letters</b> and much more. Use the <code>code tag</code> to " +
				  "mark code. Think of a good description for your extension",
    category = ComponentCategory.EXTENSION, //cannot be changed
    nonVisible = true, //cannot be changed
    iconName = "images/extension.png") //or use a http link to a publicly accessible image
@UsesPermissions(permissionNames = "android.permission.PERMISSION_NAME")
@SimpleObject(external = true) //cannot be changed
public final class YourExtension extends AndroidNonvisibleComponent { //your class name must be the same like your file name
	
	//declare variables
	private final Activity activity;
	
    /**
     * Creates a new component.
     *
     * @param container  container, component will be placed in
     */
    public YourExtension(ComponentContainer container) { //must be the same like your class name
       super(container.$form());

       activity = container.$context();
    }
}