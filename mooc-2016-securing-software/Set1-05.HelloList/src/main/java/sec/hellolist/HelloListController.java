package sec.hellolist;

import java.util.ArrayList;
import java.util.List;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloListController {

    private List<String> data;

    public HelloListController() {
        this.data = new ArrayList<>();
        this.data.add("Hello world!");
    }

    @RequestMapping("/")
    public String home(Model model, @RequestParam(required = false) String content) {
        if (content != null && !content.trim().isEmpty()) {
            this.data.add(content.trim());
        }

        model.addAttribute("list", data);
        return "index";
    }

}
