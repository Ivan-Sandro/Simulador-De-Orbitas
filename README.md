# Simulador-De-Orbitas
  Esse projeto foi criado para que o usuário possa criar suas próprias simulações de órbitas em um plano 2D, podendo salvar a configuração dos seus planetas em um arquivo de texto que o próprio programa faz para você, um arquivo criado de forma clara para que o próprio usuário possa modificar a sua configuração pelo próprio arquivo se desejar, a configuração do arquivo poderá ser lida mais tarde pelo programa para sua execução.
 
 No arquivo de ajustes se encontra ao todo 3 configurações principais do programa.
 
 Altura da janela gráfica, Largura da janela gráfica, e os FPS do programa.
 
 O programa não possui uma proporção em relação aos planetas e ao tamanho da janela, logo, ao modificar as dimensões da janela gráfica o tamanho dos planetas não será alterado, se alterar o FPS notará que a velocidade do programa não fica mais lento nem mais rápido, isso se deve pois o FPS não está interligado com a velocidade de movimentação dos corpos, mas sim a quantidade de vezes que o programa se "atualiza" em um segundo para desenhar a movimentação do planeta e verificar seu impacto, então se quiser uma verificação de colisão mais precisa, aumente o FPS, no futuro pode ocorrer uma atualização para melhorar o sistema de colisão para que ele não fique limitado pelo FPS, mas 144 a 60 de FPS é mais do que o suficiente para a maior parte das emulações.
