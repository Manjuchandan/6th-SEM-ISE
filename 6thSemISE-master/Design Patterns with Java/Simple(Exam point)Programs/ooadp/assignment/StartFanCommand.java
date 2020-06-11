/**
 * Fan Start Command where we are encapsulating both Object[fan] and the
 * operation[start] together as command. This is the essence of the command.
 *
 */
public class StartFanCommand implements ICommand {
    String f;
    Fan fan;
 
    public StartFanCommand(Fan fan,String f) {
        super();
        this.fan = fan;
	this.f =f;
    }
 
    public void execute() {
        System.out.println("starting Fan in  "+f);
        fan.start();
    }
}
