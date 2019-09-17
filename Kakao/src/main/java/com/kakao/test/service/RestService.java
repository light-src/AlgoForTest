package com.kakao.test.service;
import com.kakao.test.config.ApiInfo;
import com.kakao.test.dto.StartDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.util.UriComponentsBuilder;

@Service
public class RestService {
    private static int problemId = 0;
    private static int numberOfElevators = 4;
    @Autowired
    ApiInfo apiInfo;

    @Autowired
    RestTemplate restTemplate;

    public void postForServer(){

    }

    // /start/{user_key}/{problem_id}/{number_of_elevators}
    public void startForServer(){
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        HttpEntity<?> entity = new HttpEntity<>(headers);
        HttpEntity<StartDto> starDto = restTemplate.exchange(apiInfo.base + apiInfo.start,
                HttpMethod.POST,
                entity,
                StartDto.class,
                apiInfo.userKey,
                problemId,
                numberOfElevators
        );
        System.out.println(starDto);
    }

}
