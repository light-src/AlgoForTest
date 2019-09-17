package com.kakao.test;

import com.kakao.test.config.ApiInfo;
import com.kakao.test.service.RestService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class TestApplication implements CommandLineRunner {

    public static void main(String[] args) {
        SpringApplication.run(TestApplication.class, args);
    }

    @Autowired
    RestService restService;
    @Override
    public void run(String... args) throws Exception {
        restService.startForServer();
    }
}
