package sec.notebook;

import java.util.ArrayList;
import java.util.List;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class NotebookController {

    private List<String> notes;

    public NotebookController() {
        notes = new ArrayList<>();
    }

    @RequestMapping("/")
    public String home(Model m, @RequestParam(required = false) String content) {
         if (content != null && !content.trim().isEmpty()) {
            this.notes.add(content.trim());
        }
        if(notes.size() >= 11){
            m.addAttribute("notes", notes.subList(notes.size()-10, notes.size()));
        }else
            m.addAttribute("notes", notes);
        return "index";
    }
}
